// lib/services/camera_service.dart
import 'dart:async';
import 'package:camera/camera.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/widgets.dart';

class CameraService {
  static CameraService? _instance;
  static CameraService get instance => _instance ??= CameraService._();
  
  CameraService._();

  CameraController? _controller;
  List<CameraDescription>? _cameras;
  bool _isInitialized = false;
  StreamController<bool> _cameraStateController = StreamController<bool>.broadcast();

  // カメラの状態を監視するストリーム
  Stream<bool> get cameraStateStream => _cameraStateController.stream;
  
  // カメラが初期化されているかどうか
  bool get isInitialized {
    try {
      return _isInitialized && 
             _controller != null && 
             _controller!.value.isInitialized;
    } catch (e) {
      debugPrint('Error checking camera initialization status: $e');
      return false;
    }
  }
  
  // カメラコントローラーを取得
  CameraController? get controller => _controller;

  /// カメラを初期化
  Future<bool> initializeCamera() async {
    try {
      // 既に初期化済みの場合は成功を返す
      if (_isInitialized && _controller?.value.isInitialized == true) {
        debugPrint('Camera already initialized');
        return true;
      }
      
      // 既存のコントローラーがある場合は適切に破棄
      if (_controller != null) {
        await stopCamera();
      }
      
      // 利用可能なカメラを取得
      _cameras = await availableCameras();
      
      if (_cameras == null || _cameras!.isEmpty) {
        debugPrint('No cameras available');
        return false;
      }

      // 前面カメラを優先的に選択（VRアバター用）
      CameraDescription camera = _cameras!.first;
      for (var cam in _cameras!) {
        if (cam.lensDirection == CameraLensDirection.front) {
          camera = cam;
          break;
        }
      }

      // カメラコントローラーを作成
      _controller = CameraController(
        camera,
        ResolutionPreset.high,
        enableAudio: false,
      );

      // カメラを初期化
      await _controller!.initialize();
      
      _isInitialized = true;
      _cameraStateController.add(true);
      
      debugPrint('Camera initialized successfully');
      return true;
      
    } catch (e) {
      debugPrint('Error initializing camera: $e');
      _isInitialized = false;
      _cameraStateController.add(false);
      return false;
    }
  }

  /// カメラを開始
  Future<bool> startCamera() async {
    if (!_isInitialized) {
      final initialized = await initializeCamera();
      if (!initialized) return false;
    }
    
    try {
      if (_controller != null && !_controller!.value.isStreamingImages) {
        // カメラプレビューを開始（実際のストリーミングは自動的に開始される）
        debugPrint('Camera preview started');
        return true;
      }
      return true;
    } catch (e) {
      debugPrint('Error starting camera: $e');
      return false;
    }
  }

  /// カメラを停止
  Future<void> stopCamera() async {
    try {
      if (_controller != null) {
        // 初期化されている場合のみ破棄処理を実行
        if (_controller!.value.isInitialized) {
          await _controller!.dispose();
        }
        _controller = null;
        _isInitialized = false;
        
        // ストリームが閉じられていない場合のみ状態を送信
        if (!_cameraStateController.isClosed) {
          _cameraStateController.add(false);
        }
        debugPrint('Camera stopped and disposed');
      }
    } catch (e) {
      debugPrint('Error stopping camera: $e');
      // エラーが発生しても状態をリセット
      _controller = null;
      _isInitialized = false;
    }
  }

  /// カメラの向きを切り替え（前面/背面）
  Future<bool> switchCamera() async {
    if (_cameras == null || _cameras!.length < 2) {
      debugPrint('Cannot switch camera: not enough cameras available');
      return false;
    }

    try {
      // 現在使用中のカメラの向きを確認
      final currentCamera = _controller?.description;
      if (currentCamera == null) return false;

      // 反対向きのカメラを探す
      CameraDescription? newCamera;
      for (var camera in _cameras!) {
        if (camera.lensDirection != currentCamera.lensDirection) {
          newCamera = camera;
          break;
        }
      }

      if (newCamera == null) return false;

      // 現在のカメラを停止
      if (_controller != null && _controller!.value.isInitialized) {
        await _controller!.dispose();
      }

      // 新しいカメラでコントローラーを作成
      _controller = CameraController(
        newCamera,
        ResolutionPreset.high,
        enableAudio: false,
      );

      // 新しいカメラを初期化
      await _controller!.initialize();
      
      debugPrint('Camera switched to ${newCamera.lensDirection}');
      return true;
      
    } catch (e) {
      debugPrint('Error switching camera: $e');
      return false;
    }
  }

  /// アプリライフサイクル変更時の処理
  Future<void> handleAppLifecycleChange(AppLifecycleState state) async {
    switch (state) {
      case AppLifecycleState.paused:
      case AppLifecycleState.inactive:
      case AppLifecycleState.detached:
        // アプリがバックグラウンドに移行する時はカメラを停止
        if (_isInitialized) {
          await stopCamera();
        }
        break;
      case AppLifecycleState.resumed:
        // アプリが再開される時は必要に応じてカメラを再初期化
        // 実際の再初期化は使用画面で行う
        break;
      case AppLifecycleState.hidden:
        // Web/デスクトップ向け - タブが非表示になった時
        if (_isInitialized) {
          await stopCamera();
        }
        break;
    }
  }

  /// リソースを解放
  Future<void> dispose() async {
    try {
      // カメラコントローラーが存在し、初期化済みの場合のみ破棄
      if (_controller != null) {
        if (_controller!.value.isInitialized) {
          await _controller!.dispose();
        }
        _controller = null;
      }
      
      // 状態を更新
      _isInitialized = false;
      
      // ストリームコントローラーが閉じられていない場合のみ閉じる
      if (!_cameraStateController.isClosed) {
        _cameraStateController.add(false);
        await _cameraStateController.close();
      }
      
      _instance = null;
      debugPrint('CameraService disposed successfully');
    } catch (e) {
      debugPrint('Error disposing CameraService: $e');
    }
  }
}