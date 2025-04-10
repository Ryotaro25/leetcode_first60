# コンパイラの設定
CXX = g++
# コンパイルオプション（C++17、警告の表示、最適化、インクルードパス）
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1/

# 実行ファイル名
TARGET = coin_change
# ソースコードとヘッダファイルの相対パス
SRC = step4.cc
HDR = step4.h

# オブジェクトファイル（.o）の名前
OBJ = $(SRC:.cc=.o)

# デフォルトターゲット：実行ファイルを作成
all: $(TARGET)

# 実行ファイルを作成するルール
$(TARGET): $(OBJ)
	# オブジェクトファイルから実行ファイルを作成
	$(CXX) $(CXXFLAGS) -o $@ $^

# .cc から .o を作成するルール
%.o: %.cc $(HDR)
	# ソースコードをコンパイルしてオブジェクトファイルを生成
	$(CXX) $(CXXFLAGS) -c $< -o $@

# クリーンアップターゲット：コンパイル生成物を削除
clean:
	# コンパイルで生成されたオブジェクトファイルと実行ファイルを削除
	rm -f $(OBJ) $(TARGET)
