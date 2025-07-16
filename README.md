# VR Avatar App

GPU最適化リアルタイム人物VR化アプリ - Flutter Menu + Unity VR Integration

## 概要

このアプリは、Neural Engine + Unity GPU最適化によるリアルタイム人物VR化アプリです。Flutter でメニューUI、Unity でVR処理を行うハイブリッドアーキテクチャを採用しています。

## 技術仕様

### 対応プラットフォーム
- **iOS**: iPhone XS以降 (iOS 15.0+)
- **GPU**: A12 Bionic以降 (Neural Engine対応)

### 主要技術
- **Flutter**: メニューUI、デバイス互換性チェック
- **Unity**: GPU最適化VR処理、ポーズ推定
- **Neural Engine**: AI推論加速
- **Metal**: GPU描画最適化

## プロジェクト構成

```
vr_avatar_app/
├── lib/                    # Flutter アプリケーション
│   └── main.dart          # メインアプリ
├── ios/                   # iOS Flutter設定
├── android/               # Android Flutter設定
├── unity/                 # Unity エクスポート
│   ├── Classes/          # Unity iOS クラス
│   ├── Data/             # Unity データ
│   ├── Libraries/        # Unity ライブラリ
│   └── UnityFramework/   # Unity フレームワーク
├── pubspec.yaml          # Flutter 依存関係
├── codemagic.yaml        # CI/CD設定
└── README.md             # このファイル
```

## 主要機能

### Flutter メニュー
- **スプラッシュ画面**: デバイス互換性チェック
- **メニュー画面**: Material Design準拠UI
- **権限管理**: カメラ権限のリアルタイムチェック
- **Unity統合**: Flutter-Unity Widget 完全統合

### Unity VR処理
- **GPU最適化**: Metal API + Unity GPU最適化
- **ポーズ推定**: Neural Engine活用17キーポイント検出
- **VRキャラクター**: リアルタイム3Dアニメーション
- **人物検出**: GPU並列処理による高速検出

## 開発環境

### 必要なツール
- **Flutter**: 3.0.0以降
- **Unity**: 2023.3 LTS
- **Xcode**: 15.0以降
- **iOS SDK**: 15.0以降

### 依存関係
```yaml
dependencies:
  flutter_unity_widget: ^2022.2.0
  device_info_plus: ^9.1.0
  permission_handler: ^11.0.1
  shared_preferences: ^2.2.2
```

## ビルド方法

### Codemagic CI/CD
1. GitHub リポジトリを Codemagic に接続
2. `codemagic.yaml` 設定を確認
3. App Store Connect 証明書を設定
4. ビルド実行

### ローカルビルド
```bash
flutter packages pub get
cd ios && pod install
flutter build ipa --release
```

## 性能目標

### GPU最適化指標
- **フレームレート**: 60FPS安定
- **AI推論**: 8ms以内 (Neural Engine)
- **3D描画**: 16ms以内 (Metal)
- **総合遅延**: 33ms以内

### 対応デバイス別性能
- **iPhone 15 Pro** (A17 Pro): 60FPS安定、高品質
- **iPhone 14 Pro** (A16): 60FPS安定、標準品質
- **iPhone 13** (A15): 45-60FPS、最低品質
- **iPhone XS** (A12): 30-45FPS、基本品質

## Unity 設定

### Graphics Settings
```
Graphics APIs: Metal のみ
Scripting Backend: IL2CPP
Target Device: iPhone Only
Minimum iOS Version: 15.0
Architecture: ARM64
```

### Player Settings
```
Bundle Identifier: com.yourcompany.vravatarapp
Target minimum iOS: 15.0
API Compatibility: .NET Standard 2.1
```

## 権限設定

### iOS (Info.plist)
```xml
<key>NSCameraUsageDescription</key>
<string>VRアバター機能のためカメラアクセスが必要です</string>
```

## テスト

### デバイス互換性
- iPhone XS以降の自動検出
- iOS 15.0以降のバージョンチェック
- Neural Engine対応確認

### 性能テスト
- 60FPS安定性テスト
- GPU使用率監視
- 熱管理テスト

## デプロイ

### TestFlight
- 内部テスト用
- Codemagic 自動デプロイ

### App Store
- 本番リリース用
- 手動承認プロセス

## ライセンス

Private Repository - 商用利用制限

## 開発者

- **メイン開発者**: 1名
- **AI支援**: Claude Code
- **期間**: 3ヶ月

## バージョン

- **Current**: v1.0.0
- **Build**: GPU最適化版
- **Target**: iPhone XS以降

---

Neural Engine + Unity GPU最適化による次世代リアルタイムVR化アプリ
