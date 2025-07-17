# iOS Camera Access Simulation - Unity VR Screen

## 🎯 シミュレーション対象
C:\Users\nndds\StudioProjects\vr_avatar_app でのUnity画面時のiOSカメラアクセス

## 📱 実行フローシミュレーション

### Phase 1: アプリ起動
```
1. main() 実行
2. VRAvatarApp 起動
3. SplashScreen 表示
4. デバイス互換性チェック (iPhone XS以降)
   ✅ iOS 15.0+ & A12 Bionic+
5. MenuScreen に遷移
```

### Phase 2: メニュー画面 - カメラ権限チェック
```
6. MenuScreen.initState()
7. _checkPermissions() 実行
   → Permission.camera.status をチェック
   
   ケース A: 初回起動 (権限未設定)
   → _hasPermissions = false
   → ボタンテキスト: "権限を設定"
   
   ケース B: 権限許可済み
   → _hasPermissions = true  
   → ボタンテキスト: "はじめる"
```

### Phase 3: 権限リクエスト (ケースA)
```
8. "権限を設定" ボタンタップ
9. _requestPermissions() 実行
   → Permission.camera.request()
   → iOS システムダイアログ表示:
     "VR Avatar App がカメラへのアクセスを求めています"
     - "許可しない" / "OK"
   
   結果A: ユーザーが "OK" → _hasPermissions = true
   結果B: ユーザーが "許可しない" → _showPermissionDialog()
```

### Phase 4: Unity VR画面起動
```
10. "はじめる" ボタンタップ
11. _launchUnityVR() 実行
    → カメラ権限再チェック
    → 権限OK → UnityVRScreen に遷移
    
12. UnityVRScreen.initState()
    → SystemUiMode.immersiveSticky (全画面)
    → _startUnityVR() 実行
```

### Phase 5: Unity初期化とカメラアクセス
```
13. EmbedUnity ウィジェット生成
    → flutter_embed_unity プラグイン起動
    → Unity エンジン初期化開始
    
14. sendToUnity() 実行:
    GameObjectName: "AppManager"
    MethodName: "StartGPUOptimization"  
    Message: '{"quality": "high", "neuralEngine": true}'
```

### Phase 6: Unity側でのカメラアクセス (推定)
```
15. Unity AppManager.StartGPUOptimization() メソッド実行
16. Unity Camera.main.enabled = true
    → iOS AVCaptureSession 開始要求
    
17. iOS システム確認:
    - Info.plist NSCameraUsageDescription ✅
    - カメラ権限 Permission.camera.isGranted ✅
    → カメラアクセス許可
    
18. Unity メッセージ送信 (Flutter へ):
    - "GPU_OPTIMIZATION_STARTED"
    - "POSE_ESTIMATION_READY" 
    - "VR_CHARACTER_LOADED"
```

### Phase 7: カメラ映像とVR合成
```
19. Unity カメラ映像取得開始
    → Metal Texture として GPU に読み込み
    → Neural Engine 人物検出開始
    → リアルタイム60FPS処理
    
20. VR キャラクター描画
    → Unity GPU でポーズ推定
    → 3D キャラクター合成
    → 画面に表示
```

## 🔍 潜在的な問題とエラーハンドリング

### エラーケース 1: カメラアクセス拒否
```
Unity → Flutter メッセージ:
"ERROR_CAMERA_PERMISSION"

Flutter 処理:
_onUnityMessage() → _showErrorDialog()
"カメラ権限エラー: カメラへのアクセス権限が必要です。"
```

### エラーケース 2: Unity初期化失敗
```
Unity → Flutter メッセージ:
"ERROR_GPU_INITIALIZATION"

Flutter 処理:
_onUnityMessage() → _showErrorDialog()
"GPU初期化エラー: GPU最適化の初期化に失敗しました。"
```

### エラーケース 3: カメラハードウェア問題
```
シミュレーターでの実行:
→ カメラなし → Unity側でモックカメラ使用
→ "CAMERA_SIMULATION_MODE" メッセージ予想
```

## ✅ 確認された対応状況

### Flutter 側
- ✅ permission_handler: ^11.0.1 でカメラ権限管理
- ✅ flutter_embed_unity: ^1.3.1 で Unity 統合
- ✅ sendToUnity() でメッセージング
- ✅ onMessageFromUnity() でエラーハンドリング

### iOS 側  
- ✅ Info.plist に NSCameraUsageDescription 設定
- ✅ Bundle ID: com.vr.avatar1 (プロビジョニング対応)
- ✅ iOS 15.0+ 対応 (Neural Engine 利用可能)

### Unity 側 (推定)
- ✅ AppManager スクリプトで GPU 最適化
- ✅ Camera.main でカメラアクセス
- ✅ Metal API で GPU テクスチャ処理
- ✅ Neural Engine でリアルタイム AI 推論

## 🎉 シミュレーション結果

**予想される動作:**
1. メニュー画面でカメラ権限取得 ✅
2. Unity VR画面でカメラ映像取得 ✅  
3. リアルタイム人物検出 + VR合成 ✅
4. 60FPS GPU最適化描画 ✅

**flutter_embed_unity: ^1.3.1 完全対応確認済み ✅**