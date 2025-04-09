## ステップ1
問題文に記載の条件をそのままコードに起こした。
indexを用意してsを探索する
・スペースの間はindexを進める
・+/-の場合もindexを進めるが、intが負の数であるのかどうかを記録する
・0以外が現れるまで、indexを進める
・有効な数字(先頭は1~9でそれ以降は、　0~9)が現れた場合は配列に突っ込む
・配列から取り出し、数値型に変換しながら最終的な数値を作る

intの限界値の処理に時間がかかった。
acceptまで35分
時間計算量O(n)
空間計算量O(n)

## ステップ2
・IsNumberという関数を自作したが、C++に既にありそう
・converted == numeric_limits<int>::max() / 10 && digit > 7と言う条件を使ったが
　この7が分かりづらい気がする
・ numeric_strs[i] - '0'以外にキャストする方法は?
・longやlong long sの場合は?どうなる

・IsNumberという関数を自作したが、C++に既にありそう
  std::isdigitが存在している
  https://en.cppreference.com/w/cpp/string/byte/isdigit

・converted == numeric_limits<int>::max() / 10 && digit > 7と言う条件を使ったが
　この7が分かりづらい気がする
  絶対値を見た場合負の数側の方の一の位が8なので動く(怪しい気がする)
  -2147483647になる場合、intminにならないのでそもそもstep1は誤っている

・ numeric_strs[i] - '0'以外にキャストする方法は?
  static_cast<int>()は使えない
   >Character types are integer types used for a character representation.
    C++はのCharはintの一種でstatic_castを用いるとASCIIコードに変換されるため
    試しにやってみると確かに今回の問題とは意図しない形になった

  (int)も使えない、static_castと同じようにASCIIコードに変換される
  今回の場合、numeric_strs[i] - '0'を使うしかないのか

・longやlong long sの場合は?どうなる
  内部もそれに合わせる

## ステップ3
**3回書き直しやりましょう、といっているのは、不自然なところや負荷の高いところは覚えられないからです。**

## 他の方の解法
・long longの場合は、内部のintで計算しているところをlongやlong longに置き換えている
・C++におけるオーバーフローの検出方法についてコメントがある
  そもそもgccとclangの違いについてよく分かっていない(どちらもコンパイラですぐらい)
https://github.com/philip82148/leetcode-arai60/pull/6/commits/4e7c21a9e3cb96327ec31ece06e5c3fc1b0bbc03

・MIN = - MAX - 1の形で覚えておけばいいのか
・サインビットの部分をPositive,Negativeと変数名としておくのも分かりやすい
https://github.com/Yoshiki-Iwasa/Arai60/pull/64/commits/857ed449085ebae4c21cd475d45b541d6d43ccac

・処理ごとに関数に分けるのも一つの手段か
・Pythonのisdigit()を使わないのかなと思ったら理由が書かれていた
　>[0-9]以外もTrueにするやつがいくつかあったと思うので使うのを止めておい
　なるほどです
　C++では、ロケールの影響は受ける可能性がある
・joinして最後に変換する方法もある
　c++だと変換した瞬間にオーバーフローしそう
https://github.com/fhiyo/leetcode/pull/57/commits/981cf81c9c82ed22dcc53f6d17e8a2364b32bc92
https://github.com/Mike0121/LeetCode/pull/23

## Discordなど

## コンパイラについての調査
ISOに規格が存在する。
ISO International Standard for C++, ISO IS 14882:1998, Programming Language - C++

# gccについて
そもそもGNUとは？gccとどう関係する?
GNUとはオペレーティングシステムであり、かつコンピュータソフトウェアの広範囲に渡るコレクションである。
GNUソフトウェアとLinuxカーネルを組み合わせたものが一般的に知られるLinuxである。
GNUのカーネルにLinuxカーネルを用いるのが一般的な理由は、
GNUのカーネルがGNUの中で最も成熟していない部分のためである。
GNUのコンポーネントの一つとしてgccが存在している

gcc(GNU Compiler Collectionの略)
最新標準パッケージには C、C++、Objective-C、Objective-C++、Fortran、Ada、Go、Dのコンパイラ並びに
これらのライブラリが含まれている。なるほどだからコレクションなのか。

gccは、 実は、コンパイラドライバ(compiler driver)と呼ばれるプログラムであり、
Cなどのプログラミング言語で書かれたソースプログラムから実行形式を 作り出すための処理を行う。
gccは、「必要に応じてコンパイラや アセンブラ、リンケージエディタなどのプログラムを呼び出す」という 処理を行っている
gccコマンド自体が直接コンパイルを行っているわけではない。

# コンパイルの手順
前処理 (Preprocess)
マクロ展開やヘッダの読み込みを行い、.i ファイルに保存。
-E オプションで前処理のみ実行（結果は標準出力）。

コンパイル (Compile)
コンパイラが .i をアセンブリ .s に変換。
-S オプションでアセンブリコードのみ生成。

アセンブル (Assemble)
アセンブラが .s をオブジェクトファイル .o に変換。
-c オプションでここまでの処理を行い、リンクを省略。

連結編集 (Linkage Edit)
crt0.o（ランタイムルーチン）やライブラリをリンク(まとめる)。
対象:
  ・ソースプログラムを前処理/コンパイル/アセンブルした結果 生成されたオブジェクトプログラム
  ・プログラムの実行にあたって初期化や後処理などを行う 特別なオブジェクトプログラムである、crt0.o。(C RunTime)
  ・-lオプションで指定されたライブラリに アーカイブされたオブジェクトプログラム(後述)

-o で出力ファイル指定、未指定時は a.out。
-v で処理の詳細を確認可能。

複数のファイルをまとめて1つのファイルにすることを、 アーカイブ(archive)という。 
複数のオブジェクトプログラムを一つのファイルにアーカイブしたものを、 ライブラリ(library)という。

C言語で使われるprintf()などの標準的な関数は、 libc.aというライブラリに まとめられている。
gccは連結編集するときに自動的にlibc.aを用いるので、 libc.aに含まれている関数を使うときにはgccに明示的にライブラリ名を
指定する必要がない。しかしそれ以外のライブラリ （例えば数学ライブラリである libm.a）を使う場合には、
（例えば-lmのように）明示的にライブラリ名を指定する必要がある。


# clangについて
プログラミング言語 C、C++、Objective-C、Objective-C++ 向けのコンパイラフロントエンドである。
  コンパイラフロントエンド:　高水準言語を中間言語に翻訳するもの
  コンパイラバックエンド：　中間言語をハードウェアプラットフォームの機械語に翻訳するもの
  中間言語を挟むことで、互換性の問題を回避する(コンパイラフロントエンドは中間言語に訳すことだけに専念できる)
LLVMプロジェクトで使われている
LLVMプロジェクトとは再利用可能なコンパイラのプロジェクトの集まり？

# コンパイルの手順
  これはgccと同じ(ほぼ同じ)

# gccとclangの違いは
GCCはコンパイル処理にはマルチスレッドを用いていないので、ソース一つごとのコンパイルではマルチプロセッサのハードウェアの恩恵を受けられない。一方Clangはメモリ使用量の削減と速度の向上を目指してコンパイルの処理が最初からマルチスレッド対応で設計されている。
2007年10月の時点で、ClangはCarbonのライブラリを、メモリとディスクを1/5程度しか使用せずに、GCCの2倍以上の速度でコンパイルできる
※Carbon はPHPで日付と時間を扱うためのライブラリ

共通もコマンドもあるがgccのみやclangのみのコマンドなども存在する
https://solid.kmckk.com/SOLID/doc/latest/solid_toolchain/overview.html

The LLVM compilers (clang, clang++) give error messages that are actually (somewhat) understandable, that’s a big plus for me (dabbling in C++). GCC is getting there, though.
The suport for new/experimental language features varies, they don’t support the same.
LLVM is much more open, you can hook your own tools in to do all sorts of fancy stuff. Not for the faint hearthed.
GCC supports more source languages and targets.
For some the GPL of GCC is a turn off.
proもconのどちらもあるので、clangが完全な上位互換ではなさそう

Refs:
https://docs.oracle.com/cd/E19957-01/806-4837/intro.html#702172
https://ja.wikipedia.org/wiki/GNU
https://ja.wikipedia.org/wiki/GNU%E3%82%B3%E3%83%B3%E3%83%91%E3%82%A4%E3%83%A9%E3%82%B3%E3%83%AC%E3%82%AF%E3%82%B7%E3%83%A7%E3%83%B3
https://nenya.cis.ibaraki.ac.jp/TIPS/compiler.html
https://ja.wikipedia.org/wiki/Clang
コンピュータシステムの理論と実装
https://www.quora.com/What-are-the-advantages-and-disadvantages-of-using-Clang-over-GCC-Why-would-someone-choose-to-use-Clang-instead-of-GCC
https://www.reddit.com/r/C_Programming/comments/som4ys/gcc_or_clang/
https://www.llvm.org/

C++を使っている方々がコンパイラに対してどれだけ理解して、何を抑えているのか知りたいです。
教えていただけると幸いです。
