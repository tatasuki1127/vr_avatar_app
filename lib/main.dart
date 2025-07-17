import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_embed_unity/flutter_embed_unity.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:device_info_plus/device_info_plus.dart';
import 'package:permission_handler/permission_handler.dart';
import 'dart:io' show Platform;
import 'screens/camera_test_screen.dart';
import 'services/camera_service.dart';

void main() {
  runApp(const VRAvatarApp());
}

class VRAvatarApp extends StatelessWidget {
  const VRAvatarApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'VR Avatar App',
      theme: ThemeData(
        useMaterial3: true,
        colorScheme: ColorScheme.fromSeed(
          seedColor: const Color(0xFF2196F3),
          brightness: Brightness.dark,
        ),
        fontFamily: 'Roboto',
        appBarTheme: const AppBarTheme(
          backgroundColor: Colors.transparent,
          elevation: 0,
          foregroundColor: Colors.white,
        ),
        elevatedButtonTheme: ElevatedButtonThemeData(
          style: ElevatedButton.styleFrom(
            backgroundColor: const Color(0xFF2196F3),
            foregroundColor: Colors.white,
            minimumSize: const Size(200, 60),
            textStyle: const TextStyle(
              fontSize: 20,
              fontWeight: FontWeight.bold,
            ),
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(30),
            ),
          ),
        ),
      ),
      home: const SplashScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class SplashScreen extends StatefulWidget {
  const SplashScreen({super.key});

  @override
  State<SplashScreen> createState() => _SplashScreenState();
}

class _SplashScreenState extends State<SplashScreen>
    with TickerProviderStateMixin {
  late AnimationController _fadeController;
  late Animation<double> _fadeAnimation;
  
  bool _isCompatible = false;
  bool _isCheckingCompatibility = true;
  String _deviceInfo = '';
  
  @override
  void initState() {
    super.initState();
    
    _fadeController = AnimationController(
      duration: const Duration(seconds: 2),
      vsync: this,
    );
    
    _fadeAnimation = Tween<double>(
      begin: 0.0,
      end: 1.0,
    ).animate(CurvedAnimation(
      parent: _fadeController,
      curve: Curves.easeIn,
    ));
    
    _fadeController.forward();
    _checkDeviceCompatibility();
  }

  Future<void> _checkDeviceCompatibility() async {
    try {
      final deviceInfo = DeviceInfoPlugin();
      
      if (Platform.isIOS) {
        final iosInfo = await deviceInfo.iosInfo;
        _deviceInfo = '${iosInfo.name} (${iosInfo.systemVersion})';
        
        // iPhone XS以降をチェック (A12 Bionic以降)
        final supportedDevices = [
          'iPhone10,3', 'iPhone10,6', // iPhone X
          'iPhone11,2', 'iPhone11,4', 'iPhone11,6', 'iPhone11,8', // iPhone XS, XS Max, XR
          'iPhone12,1', 'iPhone12,3', 'iPhone12,5', // iPhone 11, 11 Pro, 11 Pro Max
          'iPhone13,1', 'iPhone13,2', 'iPhone13,3', 'iPhone13,4', // iPhone 12 シリーズ
          'iPhone14,2', 'iPhone14,3', 'iPhone14,4', 'iPhone14,5', // iPhone 13 シリーズ
          'iPhone14,6', 'iPhone14,7', 'iPhone14,8', // iPhone SE 3rd, 14 シリーズ
          'iPhone15,2', 'iPhone15,3', 'iPhone15,4', 'iPhone15,5', // iPhone 14 シリーズ
          'iPhone16,1', 'iPhone16,2', // iPhone 15 シリーズ
        ];
        
        _isCompatible = supportedDevices.any((device) => 
          iosInfo.utsname.machine.contains(device.split(',')[0]));
        
        // iOS 15.0以降もチェック
        final version = iosInfo.systemVersion.split('.').map(int.parse).toList();
        if (version[0] < 15) {
          _isCompatible = false;
        }
      } else {
        _deviceInfo = 'Android (不明)';
        _isCompatible = false; // iOS専用アプリ
      }
    } catch (e) {
      _deviceInfo = 'デバイス情報取得エラー';
      _isCompatible = false;
    }
    
    await Future.delayed(const Duration(seconds: 3));
    
    setState(() {
      _isCheckingCompatibility = false;
    });
    
    if (_isCompatible) {
      await Future.delayed(const Duration(seconds: 1));
      if (mounted) {
        Navigator.pushReplacement(
          context,
          MaterialPageRoute(builder: (context) => const MenuScreen()),
        );
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: Center(
        child: FadeTransition(
          opacity: _fadeAnimation,
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Icon(
                Icons.face_retouching_natural,
                size: 80,
                color: Color(0xFF2196F3),
              ),
              const SizedBox(height: 30),
              ShaderMask(
                shaderCallback: (bounds) => const LinearGradient(
                  colors: [Color(0xFF2196F3), Color(0xFF21CBF3)],
                ).createShader(bounds),
                child: const Text(
                  'VR Avatar App',
                  style: TextStyle(
                    fontSize: 32,
                    fontWeight: FontWeight.bold,
                    color: Colors.white,
                  ),
                ),
              ),
              const SizedBox(height: 10),
              const Text(
                'GPU最適化リアルタイム人物VR化',
                style: TextStyle(
                  fontSize: 16,
                  color: Colors.white70,
                ),
              ),
              const SizedBox(height: 50),
              if (_isCheckingCompatibility) ...[
                const CircularProgressIndicator(
                  color: Color(0xFF2196F3),
                ),
                const SizedBox(height: 20),
                const Text(
                  'デバイス互換性チェック中...',
                  style: TextStyle(color: Colors.white70),
                ),
              ] else ...[
                Icon(
                  _isCompatible ? Icons.check_circle : Icons.error,
                  size: 60,
                  color: _isCompatible ? Colors.green : Colors.red,
                ),
                const SizedBox(height: 20),
                Text(
                  _isCompatible ? 'デバイス対応済み' : 'デバイス未対応',
                  style: TextStyle(
                    fontSize: 18,
                    fontWeight: FontWeight.bold,
                    color: _isCompatible ? Colors.green : Colors.red,
                  ),
                ),
                const SizedBox(height: 10),
                Text(
                  _deviceInfo,
                  style: const TextStyle(color: Colors.white70),
                ),
                if (!_isCompatible) ...[
                  const SizedBox(height: 20),
                  const Text(
                    'このアプリはiPhone XS以降 (iOS 15.0+) が必要です',
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.red,
                      fontSize: 14,
                    ),
                  ),
                ],
              ],
              const SizedBox(height: 100),
              const Text(
                'Neural Engine + Unity GPU最適化',
                style: TextStyle(
                  fontSize: 12,
                  color: Colors.white38,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }

  @override
  void dispose() {
    _fadeController.dispose();
    super.dispose();
  }
}

class MenuScreen extends StatefulWidget {
  const MenuScreen({super.key});

  @override
  State<MenuScreen> createState() => _MenuScreenState();
}

class _MenuScreenState extends State<MenuScreen> with TickerProviderStateMixin, WidgetsBindingObserver {
  late AnimationController _pulseController;
  late Animation<double> _pulseAnimation;
  
  bool _isLoading = false;
  bool _hasPermissions = false;
  String _permissionStatus = '権限チェック中...';

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addObserver(this);
    
    _pulseController = AnimationController(
      duration: const Duration(seconds: 2),
      vsync: this,
    );
    
    _pulseAnimation = Tween<double>(
      begin: 1.0,
      end: 1.2,
    ).animate(CurvedAnimation(
      parent: _pulseController,
      curve: Curves.easeInOut,
    ));
    
    _pulseController.repeat(reverse: true);
    _checkPermissions();
  }

  @override
  void didChangeAppLifecycleState(AppLifecycleState state) {
    super.didChangeAppLifecycleState(state);
    if (state == AppLifecycleState.resumed) {
      // アプリが前面に戻った時に権限を再チェック
      Future.microtask(() => _checkPermissions());
    }
  }

  Future<void> _checkPermissions() async {
    setState(() {
      _permissionStatus = 'カメラ権限チェック中...';
    });
    
    // 実際のカメラアクセスで権限をテスト
    final cameraService = CameraService.instance;
    final canAccessCamera = await cameraService.initializeCamera();
    
    if (canAccessCamera) {
      setState(() {
        _hasPermissions = true;
        _permissionStatus = 'カメラ権限: 許可済み ✓';
      });
      // テスト後はカメラを停止
      await cameraService.stopCamera();
    } else {
      // permission_handlerで詳細な状態をチェック
      final permissionStatus = await Permission.camera.status;
      setState(() {
        _hasPermissions = false;
        if (permissionStatus.isPermanentlyDenied) {
          _permissionStatus = 'カメラ権限: 拒否済み (設定から許可が必要)';
        } else if (permissionStatus.isDenied) {
          _permissionStatus = 'カメラ権限: 未許可 (タップして許可)';
        } else {
          _permissionStatus = 'カメラ権限: アクセスできません';
        }
      });
    }
  }

  Future<void> _requestPermissions() async {
    setState(() {
      _permissionStatus = 'カメラ権限リクエスト中...';
    });

    // permission_handlerでリクエスト
    final permissionStatus = await Permission.camera.request();
    
    // リクエスト後、実際のカメラアクセスで確認
    final cameraService = CameraService.instance;
    final canAccessCamera = await cameraService.initializeCamera();
    
    if (canAccessCamera) {
      setState(() {
        _hasPermissions = true;
        _permissionStatus = 'カメラ権限: 許可済み ✓';
      });
      // テスト後はカメラを停止
      await cameraService.stopCamera();
    } else {
      setState(() {
        _hasPermissions = false;
        if (permissionStatus.isPermanentlyDenied) {
          _permissionStatus = 'カメラ権限: 拒否済み (設定から許可が必要)';
        } else {
          _permissionStatus = 'カメラ権限: 拒否されました';
        }
      });
      _showPermissionDialog();
    }
  }

  void _showPermissionDialog() {
    showDialog(
      context: context,
      builder: (context) => AlertDialog(
        backgroundColor: const Color(0xFF1E1E1E),
        title: const Text(
          'カメラ権限が必要です',
          style: TextStyle(color: Colors.white),
        ),
        content: const Text(
          'VRアバター機能を使用するには、カメラへのアクセス権限が必要です。設定からカメラ権限を有効にしてください。',
          style: TextStyle(color: Colors.white70),
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(context),
            child: const Text('キャンセル'),
          ),
          TextButton(
            onPressed: () {
              Navigator.pop(context);
              openAppSettings();
            },
            child: const Text('設定を開く'),
          ),
        ],
      ),
    );
  }

  Future<void> _launchUnityVR() async {
    if (!_hasPermissions) {
      await _requestPermissions();
      return;
    }
    
    setState(() {
      _isLoading = true;
    });
    
    try {
      await Future.delayed(const Duration(seconds: 1));
      
      if (mounted) {
        Navigator.push(
          context,
          MaterialPageRoute(
            builder: (context) => const UnityVRScreen(),
          ),
        );
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(
            content: Text('Unity VR起動エラー: ${e.toString()}'),
            backgroundColor: Colors.red,
          ),
        );
      }
    } finally {
      if (mounted) {
        setState(() {
          _isLoading = false;
        });
      }
    }
  }

  void _launchCameraTest() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => const CameraTestScreen(),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topCenter,
            end: Alignment.bottomCenter,
            colors: [
              Color(0xFF000000),
              Color(0xFF1A1A1A),
              Color(0xFF000000),
            ],
          ),
        ),
        child: SafeArea(
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                AnimatedBuilder(
                  animation: _pulseAnimation,
                  builder: (context, child) {
                    return Transform.scale(
                      scale: _pulseAnimation.value,
                      child: Container(
                        width: 120,
                        height: 120,
                        decoration: BoxDecoration(
                          shape: BoxShape.circle,
                          gradient: const LinearGradient(
                            colors: [Color(0xFF2196F3), Color(0xFF21CBF3)],
                          ),
                          boxShadow: [
                            BoxShadow(
                              color: const Color(0xFF2196F3).withOpacity(0.3),
                              spreadRadius: 10,
                              blurRadius: 20,
                            ),
                          ],
                        ),
                        child: const Icon(
                          Icons.face_retouching_natural,
                          size: 60,
                          color: Colors.white,
                        ),
                      ),
                    );
                  },
                ),
                const SizedBox(height: 40),
                ShaderMask(
                  shaderCallback: (bounds) => const LinearGradient(
                    colors: [Color(0xFF2196F3), Color(0xFF21CBF3)],
                  ).createShader(bounds),
                  child: const Text(
                    'VR Avatar',
                    style: TextStyle(
                      fontSize: 48,
                      fontWeight: FontWeight.bold,
                      color: Colors.white,
                    ),
                  ),
                ),
                const SizedBox(height: 10),
                const Text(
                  'GPU最適化リアルタイム人物VR化',
                  style: TextStyle(
                    fontSize: 16,
                    color: Colors.white70,
                  ),
                ),
                const SizedBox(height: 80),
                AnimatedContainer(
                  duration: const Duration(milliseconds: 300),
                  child: ElevatedButton(
                    onPressed: _isLoading ? null : _launchUnityVR,
                    style: ElevatedButton.styleFrom(
                      backgroundColor: _hasPermissions 
                          ? const Color(0xFF2196F3) 
                          : Colors.orange,
                      minimumSize: const Size(250, 70),
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(35),
                      ),
                      elevation: 10,
                    ),
                    child: _isLoading
                        ? const SizedBox(
                            width: 20,
                            height: 20,
                            child: CircularProgressIndicator(
                              color: Colors.white,
                              strokeWidth: 2,
                            ),
                          )
                        : Text(
                            _hasPermissions ? 'はじめる' : '権限を設定',
                            style: const TextStyle(
                              fontSize: 24,
                              fontWeight: FontWeight.bold,
                              color: Colors.white,
                            ),
                          ),
                  ),
                ),
                const SizedBox(height: 20),
                // カメラテストボタン
                ElevatedButton(
                  onPressed: _launchCameraTest,
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.green,
                    minimumSize: const Size(200, 50),
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(25),
                    ),
                  ),
                  child: const Text(
                    'カメラテスト',
                    style: TextStyle(
                      fontSize: 18,
                      fontWeight: FontWeight.bold,
                      color: Colors.white,
                    ),
                  ),
                ),
                const SizedBox(height: 30),
                // 権限状態表示
                Container(
                  padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
                  decoration: BoxDecoration(
                    color: _hasPermissions 
                        ? Colors.green.withOpacity(0.2) 
                        : Colors.orange.withOpacity(0.2),
                    borderRadius: BorderRadius.circular(10),
                    border: Border.all(
                      color: _hasPermissions ? Colors.green : Colors.orange,
                      width: 1,
                    ),
                  ),
                  child: Text(
                    _permissionStatus,
                    style: TextStyle(
                      color: _hasPermissions ? Colors.green : Colors.orange,
                      fontSize: 14,
                      fontWeight: FontWeight.bold,
                    ),
                    textAlign: TextAlign.center,
                  ),
                ),
                const SizedBox(height: 50),
                Container(
                  padding: const EdgeInsets.all(20),
                  decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.05),
                    borderRadius: BorderRadius.circular(15),
                  ),
                  child: const Column(
                    children: [
                      Text(
                        '✨ 特徴',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                          color: Colors.white,
                        ),
                      ),
                      SizedBox(height: 10),
                      Text(
                        '• Neural Engine AI搭載\n• 60FPS GPU最適化\n• リアルタイム人物検出\n• 瞬時VRキャラクター化',
                        textAlign: TextAlign.center,
                        style: TextStyle(
                          fontSize: 14,
                          color: Colors.white70,
                          height: 1.5,
                        ),
                      ),
                    ],
                  ),
                ),
                const SizedBox(height: 40),
                const Text(
                  'v1.0.0 - GPU最適化版',
                  style: TextStyle(
                    fontSize: 12,
                    color: Colors.white38,
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  @override
  void dispose() {
    WidgetsBinding.instance.removeObserver(this);
    _pulseController.dispose();
    super.dispose();
  }
}

class UnityVRScreen extends StatefulWidget {
  const UnityVRScreen({super.key});

  @override
  State<UnityVRScreen> createState() => _UnityVRScreenState();
}

class _UnityVRScreenState extends State<UnityVRScreen> {
  bool _isUnityReady = false;
  bool _isFlutterUnityBridgeReady = false;
  String _statusMessage = 'Flutter-Unity通信初期化中...';

  @override
  void initState() {
    super.initState();
    SystemChrome.setEnabledSystemUIMode(SystemUiMode.immersiveSticky);
    _initializeFlutterUnityBridge();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: _isUnityReady && _isFlutterUnityBridgeReady
          ? EmbedUnity(
              onMessageFromUnity: _onUnityMessage,
            )
          : _buildLoadingScreen(),
    );
  }

  Widget _buildLoadingScreen() {
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
            const CircularProgressIndicator(
              color: Color(0xFF2196F3),
              strokeWidth: 3,
            ),
            const SizedBox(height: 30),
            Text(
              _statusMessage,
              style: const TextStyle(
                fontSize: 18,
                color: Colors.white,
              ),
            ),
            const SizedBox(height: 20),
            const Text(
              'Unity GPU最適化システム起動中...',
              style: TextStyle(
                fontSize: 14,
                color: Colors.white70,
              ),
            ),
          ],
        ),
      ),
    );
  }

  /// <summary>
  /// Flutter-Unity通信ブリッジの初期化
  /// null pointer crashを防ぐため、段階的に初期化
  /// </summary>
  void _initializeFlutterUnityBridge() async {
    setState(() {
      _statusMessage = 'Flutter-Unity通信初期化中...';
    });
    
    // Step 1: Flutter側の準備確認
    await Future.delayed(const Duration(milliseconds: 500));
    
    setState(() {
      _statusMessage = 'Unity Framework準備中...';
      _isFlutterUnityBridgeReady = true;
    });
    
    // Step 2: Unity Framework初期化待機
    await Future.delayed(const Duration(milliseconds: 1000));
    
    setState(() {
      _statusMessage = 'Unity VRシステム開始...';
      _isUnityReady = true;
    });
    
    // Step 3: Unity初期化後、安全にメッセージ送信
    await Future.delayed(const Duration(milliseconds: 500));
    
    if (_isUnityReady && _isFlutterUnityBridgeReady) {
      _startUnityVR();
    }
  }
  
  void _startUnityVR() {
    setState(() {
      _statusMessage = 'Unity GPU最適化開始...';
    });
    
    // Unity GPU最適化開始
    try {
      sendToUnity(
        'AppManager',
        'StartGPUOptimization',
        '{"quality": "high", "neuralEngine": true}',
      );
    } catch (e) {
      print('Unity通信エラー: $e');
      setState(() {
        _statusMessage = 'Unity通信エラー: $e';
      });
    }
  }

  void _onUnityMessage(String message) {
    print('Unity Message: $message');
    
    // Unity通信の安全性確認
    if (!_isFlutterUnityBridgeReady) {
      print('Flutter-Unity通信未準備のため、メッセージを無視: $message');
      return;
    }
    
    switch (message) {
      case 'UNITY_INITIALIZED':
        setState(() {
          _statusMessage = 'Unity初期化完了';
        });
        break;
      case 'UNITY_SYSTEMS_READY':
        setState(() {
          _isUnityReady = true;
          _statusMessage = 'Unity VR準備完了';
        });
        break;
      case 'SCENE_LOADED':
        setState(() {
          _statusMessage = 'Unity シーン読み込み完了';
        });
        break;
      case 'GPU_OPTIMIZATION_STARTED':
        setState(() {
          _statusMessage = 'GPU最適化開始';
        });
        break;
      case 'POSE_ESTIMATION_READY':
        setState(() {
          _statusMessage = 'ポーズ推定準備完了';
        });
        break;
      case 'VR_CHARACTER_LOADED':
        setState(() {
          _statusMessage = 'VRキャラクター読み込み完了';
        });
        break;
      case 'EXIT_VR':
        _exitVR();
        break;
      case 'ERROR_CAMERA_PERMISSION':
        _showErrorDialog('カメラ権限エラー', 'カメラへのアクセス権限が必要です。');
        break;
      case 'ERROR_GPU_INITIALIZATION':
        _showErrorDialog('GPU初期化エラー', 'GPU最適化の初期化に失敗しました。');
        break;
      default:
        if (message.startsWith('ERROR_')) {
          _showErrorDialog('エラー', message);
        }
        break;
    }
  }


  void _showErrorDialog(String title, String message) {
    showDialog(
      context: context,
      builder: (context) => AlertDialog(
        backgroundColor: const Color(0xFF1E1E1E),
        title: Text(
          title,
          style: const TextStyle(color: Colors.white),
        ),
        content: Text(
          message,
          style: const TextStyle(color: Colors.white70),
        ),
        actions: [
          TextButton(
            onPressed: () {
              Navigator.pop(context);
              _exitVR();
            },
            child: const Text('戻る'),
          ),
        ],
      ),
    );
  }

  void _exitVR() {
    SystemChrome.setEnabledSystemUIMode(SystemUiMode.edgeToEdge);
    Navigator.pop(context);
  }

  @override
  void dispose() {
    SystemChrome.setEnabledSystemUIMode(SystemUiMode.edgeToEdge);
    super.dispose();
  }
}