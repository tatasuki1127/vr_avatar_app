# AI Models for VR Avatar App

## 必要なモデルファイル

### 1. 人物検出モデル
- **ファイル名**: `person_detection_model.onnx`
- **入力サイズ**: 224×224×3 (RGB)
- **出力形式**: [confidence, x, y, width, height, ...keypoints]
- **推奨モデル**: YOLOv8-pose, MediaPipe Person

### 2. ポーズ推定モデル
- **ファイル名**: `pose_estimation_model.onnx`
- **入力サイズ**: 224×224×3 (RGB)
- **出力形式**: 17キーポイント座標 + 信頼度
- **推奨モデル**: MediaPipe Pose, OpenPose

## モデル入手方法

### Option 1: MediaPipe Pose (推奨)
```bash
# 1. MediaPipeモデルをダウンロード
wget https://storage.googleapis.com/mediapipe-models/pose_landmarker/pose_landmarker_lite/float16/latest/pose_landmarker_lite.task

# 2. TensorFlow Lite to ONNX変換
pip install tf2onnx tensorflow
python -m tf2onnx.convert --saved-model pose_landmarker_lite.task --output pose_estimation_model.onnx
```

### Option 2: YOLOv8-pose
```bash
# 1. Ultralyticsインストール
pip install ultralytics

# 2. YOLOv8-poseモデルをONNXでエクスポート
python -c "
from ultralytics import YOLO
model = YOLO('yolov8n-pose.pt')
model.export(format='onnx', imgsz=224, optimize=True, half=True)
"
```

### Option 3: OpenPose
```bash
# 1. OpenPoseリポジトリをクローン
git clone https://github.com/CMU-Perceptual-Computing-Lab/openpose.git

# 2. 事前訓練済みモデルをダウンロード
cd openpose/models
./getModels.sh

# 3. Caffe to ONNX変換
pip install caffe2onnx
python -c "
import caffe2onnx
caffe2onnx.convert('pose_iter_440000.caffemodel', 'pose_deploy.prototxt', 'pose_estimation_model.onnx')
"
```

## 簡単な方法（テスト用）

### 事前変換済みモデル
以下のリンクから事前に変換済みのモデルをダウンロードできます：

1. **MediaPipe Pose ONNX**
   - https://github.com/PINTO0309/PINTO_model_zoo/tree/main/053_BlazePose
   - ファイル: `pose_landmark_full.onnx`

2. **YOLOv8-pose ONNX**
   - https://github.com/ultralytics/ultralytics/releases
   - ファイル: `yolov8n-pose.onnx`

### ダウンロード後の設定

1. **ファイル配置**
   ```
   Assets/StreamingAssets/Models/
   ├── person_detection_model.onnx
   └── pose_estimation_model.onnx
   ```

2. **Unity Editor設定**
   - AISystem の PersonDetector コンポーネント
   - `Pose Detection Model` フィールドにモデルファイルを設定

   - AISystem の UnityPoseEstimator コンポーネント
   - `Pose Model` フィールドにモデルファイルを設定
   - `Pose Compute Shader` フィールドに PoseEstimationShader を設定

3. **テスト実行**
   - AITestManager コンポーネントを追加
   - Play モードで自動テストが実行される

## トラブルシューティング

### モデルが読み込めない場合
1. ファイルパスの確認
2. ONNXファイルの形式確認
3. Unity Barracudaの対応バージョン確認

### 性能が出ない場合
1. モデルサイズの最適化
2. 量子化（INT8）の適用
3. Neural Engine対応の確認

### iOS実機で動作しない場合
1. Neural Engine対応モデルの使用
2. Metal Performance Shaders の有効化
3. iOS Build Settings の確認

## 参考リンク

- [Unity Barracuda Documentation](https://docs.unity3d.com/Packages/com.unity.barracuda@3.0/manual/index.html)
- [MediaPipe Solutions](https://developers.google.com/mediapipe/solutions)
- [Ultralytics YOLOv8](https://github.com/ultralytics/ultralytics)
- [OpenPose](https://github.com/CMU-Perceptual-Computing-Lab/openpose)
- [ONNX Model Zoo](https://github.com/onnx/models)

## ライセンス

各モデルのライセンスを確認してください：
- MediaPipe: Apache License 2.0
- YOLOv8: AGPL v3.0
- OpenPose: Custom License (商用利用要確認)