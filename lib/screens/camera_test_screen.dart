// lib/screens/camera_test_screen.dart
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:camera/camera.dart';
import '../services/camera_service.dart';

class CameraTestScreen extends StatefulWidget {
  const CameraTestScreen({super.key});

  @override
  State<CameraTestScreen> createState() => _CameraTestScreenState();
}

class _CameraTestScreenState extends State<CameraTestScreen> with WidgetsBindingObserver {
  bool _isCameraMode = false;
  final CameraService _cameraService = CameraService.instance;
  String _statusMessage = 'カメラ準備中...';

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addObserver(this);
    _initializeCamera();
  }

  @override
  void dispose() {
    WidgetsBinding.instance.removeObserver(this);
    if (_isCameraMode) {
      _isCameraMode = false;
      _cameraService.stopCamera().catchError((error) {
        debugPrint('Error stopping camera during dispose: $error');
      });
    }
    super.dispose();
  }

  @override
  void didChangeAppLifecycleState(AppLifecycleState state) {
    super.didChangeAppLifecycleState(state);
    _cameraService.handleAppLifecycleChange(state).catchError((error) {
      debugPrint('Error handling app lifecycle change: $error');
    });
  }

  Future<void> _initializeCamera() async {
    setState(() {
      _statusMessage = 'カメラ初期化中...';
    });

    final success = await _cameraService.startCamera();
    if (success && mounted) {
      setState(() {
        _isCameraMode = true;
        _statusMessage = 'カメラ準備完了';
      });
    } else {
      if (mounted) {
        setState(() {
          _isCameraMode = false;
          _statusMessage = 'カメラの初期化に失敗しました';
        });
      }
    }
  }

  Future<void> _toggleCamera() async {
    if (_isCameraMode) {
      // カメラを停止
      setState(() {
        _isCameraMode = false;
        _statusMessage = 'カメラ停止中...';
      });
      await _cameraService.stopCamera();
      setState(() {
        _statusMessage = 'カメラ停止';
      });
    } else {
      // カメラを開始
      setState(() {
        _statusMessage = 'カメラ開始中...';
      });
      final success = await _cameraService.startCamera();
      if (success && mounted) {
        setState(() {
          _isCameraMode = true;
          _statusMessage = 'カメラ準備完了';
        });
      } else {
        setState(() {
          _statusMessage = 'カメラの開始に失敗しました';
        });
      }
    }
  }

  Future<void> _switchCamera() async {
    if (!_isCameraMode) return;
    
    setState(() {
      _statusMessage = 'カメラ切り替え中...';
    });

    final success = await _cameraService.switchCamera();
    setState(() {
      _statusMessage = success ? 'カメラ切り替え完了' : 'カメラ切り替え失敗';
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        backgroundColor: Colors.transparent,
        elevation: 0,
        leading: IconButton(
          icon: const Icon(Icons.arrow_back_ios, color: Colors.white),
          onPressed: () => Navigator.pop(context),
        ),
        title: const Text(
          'カメラテスト',
          style: TextStyle(color: Colors.white, fontSize: 18),
        ),
        actions: [
          IconButton(
            icon: Icon(
              _isCameraMode ? Icons.camera_alt : Icons.camera_alt_outlined,
              color: _isCameraMode ? const Color(0xFF2196F3) : Colors.white70,
            ),
            onPressed: _toggleCamera,
            tooltip: _isCameraMode ? 'カメラを停止' : 'カメラを開始',
          ),
          if (_isCameraMode)
            IconButton(
              icon: const Icon(Icons.switch_camera, color: Colors.white70),
              onPressed: _switchCamera,
              tooltip: 'カメラを切り替え',
            ),
        ],
      ),
      body: Container(
        width: double.infinity,
        height: double.infinity,
        child: _buildContent(),
      ),
    );
  }

  Widget _buildContent() {
    if (_isCameraMode && 
        _cameraService.isInitialized && 
        _cameraService.controller != null &&
        _cameraService.controller!.value.isInitialized &&
        mounted) {
      // カメラプレビューを表示
      return Stack(
        children: [
          // カメラプレビュー（フルスクリーン）
          SizedBox(
            width: double.infinity,
            height: double.infinity,
            child: FittedBox(
              fit: BoxFit.cover,
              child: SizedBox(
                width: _cameraService.controller!.value.previewSize?.height ?? 1,
                height: _cameraService.controller!.value.previewSize?.width ?? 1,
                child: CameraPreview(_cameraService.controller!),
              ),
            ),
          ),
          // ステータス表示
          Positioned(
            bottom: 100,
            left: 20,
            right: 20,
            child: Container(
              padding: const EdgeInsets.all(16),
              decoration: BoxDecoration(
                color: Colors.black.withOpacity(0.7),
                borderRadius: BorderRadius.circular(12),
              ),
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: [
                  Text(
                    _statusMessage,
                    style: const TextStyle(
                      color: Colors.white,
                      fontSize: 16,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 8),
                  const Text(
                    'カメラが正常に動作しています',
                    style: TextStyle(
                      color: Colors.green,
                      fontSize: 14,
                    ),
                  ),
                ],
              ),
            ),
          ),
        ],
      );
    } else {
      // ローディング/エラー画面
      return Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topCenter,
            end: Alignment.bottomCenter,
            colors: [
              Color(0xFF000000),
              Color(0xFF1A1A1A),
            ],
          ),
        ),
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              if (_statusMessage.contains('初期化中') || _statusMessage.contains('開始中'))
                const CircularProgressIndicator(
                  color: Color(0xFF2196F3),
                  strokeWidth: 3,
                ),
              if (_statusMessage.contains('失敗'))
                const Icon(
                  Icons.error,
                  size: 60,
                  color: Colors.red,
                ),
              if (!_statusMessage.contains('初期化中') && 
                  !_statusMessage.contains('開始中') && 
                  !_statusMessage.contains('失敗'))
                const Icon(
                  Icons.camera_alt_outlined,
                  size: 60,
                  color: Colors.white70,
                ),
              const SizedBox(height: 30),
              Text(
                _statusMessage,
                style: const TextStyle(
                  fontSize: 18,
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                ),
                textAlign: TextAlign.center,
              ),
              const SizedBox(height: 20),
              if (_statusMessage.contains('失敗'))
                ElevatedButton(
                  onPressed: _initializeCamera,
                  style: ElevatedButton.styleFrom(
                    backgroundColor: const Color(0xFF2196F3),
                    padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 15),
                  ),
                  child: const Text(
                    '再試行',
                    style: TextStyle(color: Colors.white, fontSize: 16),
                  ),
                ),
            ],
          ),
        ),
      );
    }
  }
}