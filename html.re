= HTML

//lead{
本章ではHTMLの基礎について説明します。代表的な要素の意味と使い方を学び、Webアプリの画面を構築できるようになりましょう。
//}

== HTMLとは

HTMLとはHyperText Markup Languageの略で、ハイパーテキストを記述するためのマークアップ言語の1つです。WebブラウザはこのHTMLを解釈し、画面に文字列や画像を表示します。@<list>{html}はHTMLで記述した文書の例です。

//list[html][HTMLの例]{
<html>
  <head>
    <meta charset="utf-8">
    <title>HTMLの例</title>
  </head>
  <body>
    <h1>HTMLの例</h1>
    <p>HTMLはこのように記述するマークアップ言語です。</p>
  </body>
</html>
//}

== HTMLの構造とタグ

HTMLは文書を木構造で表現します。構造に登場するものを要素と呼びます。

//image[html_structure][HTMLは木構造]{
//}

この構造を表現するため、HTMLでは「<」ではじまり「>」で終わる「タグ」を使用します。<>内には要素名を記述します。

タグには次の2種類があります。

 * 開始タグ：要素の開始を示す。<要素名>で記述する
 * 終了タグ：要素の終了を示す。</要素名>で記述する

開始タグと終了タグで囲まれた部分が要素の中身となります。次の例は、p要素をHTMLで記述したものです。この要素の中身は「p要素は段落を表します。」となります。

//emlist{
<p>p要素は段落を表します。</p>
//}

=== 練習問題

1 次のタグは開始タグと終了タグのどちらか？

 1. <link>
 2. </section>
 3. <code>
 4. <li>
 5. </select>

2 次のタグの要素名を答えよ

 1. <title>
 2. <head>
 3. <meta>
 4. <ol>
 5. <div>

== 属性

各要素には内容以外にも情報を付加することができます。この付加する情報を属性と呼びます。属性は「属性名="値"」という形式で指定します。@<list>{attr}はdiv要素にid属性を付与した例です。

//list[attr][属性を付与した例]{
<div id="main">
  <h1>メインコンテンツ</h1>
</div>
//}

属性を複数指定する場合は、スペース区切りとします。

//list[attr2][複数の属性を付与した例]{
<img src="./icon.png" alt="アイコン画像">
//}

要素によって指定可能な属性は異なります。詳しくは@<hd>{代表的な要素}で説明します。

=== 練習問題

次の要素に指定されている属性の名前と値をそれぞれ答えよ

 1. <a name="top">...</a>
 2. <form method="POST" action="./register">...</form>
 3. <input type="text" maxlength="10">
 4. <span style="font-size: 18px">...</span>

===[column] HTMLタグ一覧？

古い書籍やWebサイトでは、「<p>タグは段落を表します」といった表現をしているものがありますが、これは誤りです。<p>タグはp要素の開始を表すもので、</p>とセットではじめて段落を表す要素になります。

===[/column]

== 代表的な要素

本節ではHTMLでよく用いられる要素を説明します。現時点で扱うことのできる全要素は@<href>{https://developer.mozilla.org/ja/docs/Web/HTML/Element}で確認できます。

=== html

html要素はHTML文書の起点となる要素です。これから紹介する他の要素はすべてこのhtml要素の子孫要素として配置する必要があります。

=== head

head要素はHTML文書に関する情報を記述するための要素です。文書のタイトルや、文字コードの指定などといった情報を子要素で記述します。

=== title

title要素はHTML文書のタイトルを指定する要素です。head要素の子要素として指定します。@<list>{title}は文書タイトルとして「HTML基礎」を指定した例です。ブラウザでは@<img>{title}のようにウィンドウのタイトルとして表示されます。

//list[title][title要素でタイトルを指定する]{
<!DOCTYPE html>
<html>
  <head>
    <title>HTML基礎</title>
  </head>
  <body>
    <h1>1章</h1>
  </body>
</html>
//}

//image[title][title要素の値はタブに表示される]{
//}

=== meta

meta要素はHTML文書に関する任意のデータを記述するための要素です。head要素の子要素として指定します。meta要素の大事な役割として文書のエンコーディングを指定する役割があります。@<list>{meta-charset}は文書エンコーディングをUTF-8に指定した例です。

//list[meta-charset][meta要素でエンコーディングを指定する]{
<html>
  <head>
    <meta charset="utf-8">
  </head>
</html>
//}

=== link

link要素はこの文書と外部リソース（ファイルなど）との関係を指定するための要素です。head要素の子要素として指定します。主に@<chapref>{css}で説明するスタイルシートのファイルを指定するのに使用します。@<list>{link-css}はスタイルシートのファイルとしてmain.cssを指定する例です。

//list[link-css][CSSファイルを指定する]{
<html>
  <head>
    <link rel="stylesheet" type="text/css" href="main.css"> 
  </head>
</html>
//}

=== script

script要素は実行できるスクリプト（プログラム）を指定するための要素です。主にブラウザで実行可能なJavaScriptという言語で書かれたプログラムを指定します。詳しくは@<chapref>{js}で説明します。

=== body

body要素はHTML文書の本文を表す要素です。ブラウザで表示するための要素はこのbody要素の子要素として記述します。

=== h1〜h6

h1〜h6要素は見出しを表す要素です。数値で見出しの段階を表し、h1要素が最上位でh6が最下位です。

//list[h1h6][見出し要素]{
<html>
  <head>
    <!-- 中略 -->
  </head>
  <body>
    <h1>情報処理演習</h1>
    <h2>本演習の目的</h2>
    <p>本演習では、Webアプリケーション開発を学びます。</p>

    <h2>評価方法について</h2>
    <p>本演習の評価は次のように行います。</p>
  </body>
</html>
//}

ブラウザでは、見出しの段階に応じて文字サイズが変化します（@<img>{h_elem}）。

//image[h_elem][見出しの段階に応じて文字サイズが違う]{
//}

=== p

p要素は段落を表す要素です。文章はこのp要素の内容として記述することが多いでしょう。

//list[p_elem][p要素]{
<html>
  <head>
    <!-- 中略 -->
  </head>
  <body>
    <p>吾輩わがはいは猫である。名前はまだ無い。</p>
    <p>どこで生れたかとんと見当けんとうがつかぬ。何でも薄暗いじめじめした所でニャーニャー泣いていた事だけは記憶している。</p>
  </body>
</body>
//}

=== ul/olとli

ulとol要素はリストを表す要素です。ulは順序の無いリストを表し、olは順序のあるリストを表します。リストの項目はli要素で表します。

//list[ul][順序なしリスト]{
<html>
  <head>
    <!-- 中略 -->
  </head>
  <body>
    <h1>単位取得に必要な要素</h1>
    <ul>
      <li>出席点：60%</li>
      <li>レポート点：20%</li>
      <li>小テスト：20%</li>
    </ul>
  </body>
</html>
//}

@<list>{ul}をブラウザで表示させたものが@<img>{ul}です。リストの各項目の先頭には・が表示され、リストであることを示しています。

//image[ul][リスト表示]{
//}

=== pre

pre要素は整形済みテキストを表す要素です。p要素などの中で@<list>{pre1}のように改行してもブラウザでは無視されます。

//list[pre1][p要素内での改行は無視される]{
<!DOCTYPE html>
<html>
  <head>
    <title>p要素内で改行</title>
  </head>
  <body>
    <p>p要素だと
改行は
反映
されません。。。
      </p>
  </body>
</html>
//}

//image[pre1][改行が無視された例]{
//}

一方、pre要素中の改行はそのまま改行として表示されます。ソースコードといった改行が重要な意味をもつテキストの表示に使用しましょう。

//list[pre2][preを使ってソースコードを表示]{
<!DOCTYPE html>
<html>
  <head>
    <title>pre要素で改行</title>
  </head>
  <body>
    <h1>はじめてのJavaプログラム</h1>
    <pre>
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world");
    }
}
      </pre>
  </body>
</html>
//}

@<list>{pre2}をブラウザで表示させた例が@<img>{pre2}です。

//image[pre2][pre要素で表示した例]{
//}

=== br

br要素はp要素の中などで改行する際に使用します。終了タグなしで使用する点に注意しましょう。

//list[br][brによる改行]{
<!DOCTYPE html>
<html>
  <head>
    <title>brによる改行</title>
  </head>
  <body>
    <p>「山賊王に、オレはなる！」<br>と、彼はみかん箱の上で叫んでいた</p>
  </body>
</html>
//}

@<list>{br}をブラウザで表示させたものが@<img>{br}です。brの位置で改行されていることがわかります。

//image[br][ブラウザではbrで改行されている]{
//}

=== div

div要素は汎用のブロック要素です。@<chapref>{css}で説明するCSSによるスタイルを行うために使用します。

=== a

a要素はアンカー要素と呼び、リンクを作成するための要素です。リンク先はhref属性で指定します。@<list>{a-url}はgoogle.comへのリンクを指定した例です。

//list[a-url][リンクを指定する]{
<html>
  <head>
    <!-- 中略 -->
  </head>
  <body>
    <p>Webで検索するには<a href="https://google.com">Google</a>にアクセスします。</p>
  </body>
</html>
//}

=== img

img要素は画像を表示するための要素です。どの画像を表示するかはsrc属性で指定します。画像をみることができないユーザーのために、alt属性で画像に対する説明を記述しましょう。

//list[img][img要素で画像を表示する]{
<html>
  <head>
    <!-- 中略 -->
  </head>
  <body>
    <h1>モケラさん</h1>
    <img src="./moke.png" alt="モケラの画像">
  </body>
</html>
//}

=== input

input要素はデータの入力に関する要素です。type属性で入力欄の種類を指定します。@<table>{inputtype}に代表的な値を示します。

//table[inputtype][typeに指定可能な値]{
値	説明
--------------
text	1行のテキスト入力欄
password	パスワード入力欄
checkbox	チェックボックス
number	数値入力欄
date	日付入力欄
//}

@<list>{input1}はさまざまな入力欄を配置してみた例です。ブラウザで表示すると@<img>{input1}のように表示されます。

//list[input1][さまざまな入力欄]{
<!DOCTYPE html>
<html>
  <head>
    <title>input要素</title>
  </head>
  <body>
    <div>
      <input type="text" placeholder="テキスト入力欄"><br>
      <input type="password" placeholder="パスワード"><br>
      <input type="checkbox">パスワードを保存する<br>
      <input type="date" placeholder="生年月日"><br>
    </div>
  </body>
</html>
//}

//image[input1][さまざまな入力欄]{
//}

== ブロック要素とインライン要素

前節で説明した各要素はブロック要素とインライン要素に分類されます。ブロック要素とは文字通りブロック（かたまり）として表示される要素で、h1やpなどがこれに該当します。ブロック要素は基本的に新しい行から表示されます。ブロック要素の中には別のブロック要素やインライン要素を配置することができます。それに対しインライン要素とは行の中で使用される要素で、前後に改行ははいりません。aやimgなどがこれに該当します。ブロック要素の中には別のブロック要素やインライン要素が配置できるのに対し、インライン要素の中にはインライン要素のみ配置できます。

ブロック要素とインライン要素の違いを確認するため、@<list>{block}をブラウザで表示させてみましょう。表示させてみた例が@<img>{block}です。@<img>{block}では各要素の境界を表示するよう、スタイル設定を加えています。

//list[block][ブロック要素とインライン要素]{
<!DOCTYPE html>
<html>
  <head>
    <title>ブロック要素とインライン要素</title>
  </head>
  <body>

    <h1>見出しはブロック要素</h1>
    <p>インライン要素は<strong>本文の中で</strong>使用します。</p>
  </body>
</html>
//}

//image[block][ブロック要素とインライン要素][scale=0.8]{
//}



