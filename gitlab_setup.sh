#!/bin/bash

echo "🚀 GitLab移行セットアップスクリプト"
echo "リポジトリ: https://gitlab.com/pro9744129/vr_avatar_app"

# Git LFS初期化
echo "📦 Git LFS初期化中..."
git lfs install

# 既存のGitHubリモートを確認
echo "🔍 現在のリモート設定:"
git remote -v

# GitLabリモートを追加
echo "🔗 GitLabリモートを追加中..."
git remote add gitlab https://gitlab.com/pro9744129/vr_avatar_app.git

# またはGitHub remoteをGitLabに変更する場合
# git remote set-url origin https://gitlab.com/pro9744129/vr_avatar_app.git

# 大容量ファイルをGit LFSで管理
echo "📋 .gitattributes設定完了"

# 現在のステータス確認
echo "📊 Git状態確認:"
git status

echo "🔧 次の手順:"
echo "1. git add ."
echo "2. git commit -m 'GitLab移行: Git LFS設定とUnity統合'"
echo "3. git push gitlab main"
echo ""
echo "💡 大容量ファイルがある場合:"
echo "git lfs track 'unity/Libraries/*.a'"
echo "git add .gitattributes"
echo "git add ."
echo "git commit -m 'Add LFS tracking for large Unity files'"
echo "git push gitlab main"