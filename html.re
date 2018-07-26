= HTML

//lead{
本章ではHTMLの基礎について説明します。
//}

== HTMLとは

HTMLとはHyperText Markup Languageの略で、ハイパーテキストを記述するためのマークアップ言語の1つです。WebブラウザはこのHTMLを解釈し、画面に文字列や画像を表示します。そのため、Webブラウザで文字列や画像を表示するには、このHTMLで記述することになります。

== HTMLの構造とタグ

HTMLは文書を木構造で表現します。構造に登場するものを要素と呼びます。

この要素を表現するため、HTMLでは<ではじまり>で終わる「タグ」を使用します。<>内には要素名を記述します。

タグには次の2種類があります。

 * 開始タグ：要素の開始を示す。<要素名>で記述する
 * 開始タグ：要素の終了を示す。</要素名>で記述する

次の例は、p要素をHTMLで記述したものです。

//emlist{
<p>p要素は段落を表します。</p>
//}

=== 練習問題

次のタグは何を表しているか答えよ。例：<p>は、p要素の開始を表します。

 1. <link>
 2. </section>
 3. <code>
 4. <li>
 5. </select>

===[column] HTMLタグ一覧？

古い書籍やWebサイトでは、「<p>タグは段落を表します」といった表現をしてたりしますが、これは誤りです。<p>タグはp要素の開始を表すもので、</p>とセットではじめて段落を表す要素になります。

===[/column]

== 基本構造

HTMLはhtml要素を起点とした木構造で記述します。html要素の子には文書に関する情報を扱うhead要素と、本文を表すbody要素を配置します。

//list[basic][HTMLの基本構造]{
<html>
  <head>
    <meta charset="utf-8">
    <title>文書タイトル</title>
  </head>
  <body>
    <h1>HTMLの構造</h1>
  </body>
</html>
//}

== 代表的な要素

本節ではHTMLでよく用いられる要素を説明します。現時点で扱うことのできる全要素は@<href>{https://developer.mozilla.org/ja/docs/Web/HTML/Element}で確認できます。

=== html

=== head

=== title

=== link

=== body

=== h1〜h6

=== p

=== ul/olとli

=== divとsection


