= CSS

//lead{
本章ではCSSの基礎について説明します。指定方法をまなび、見栄えのよいWebアプリを作れるようになりましょう。
//}

== CSSとは

CSSとはカスケーディングスタイルシートの略で、Webページの表示方法を指示するための言語です。HTMLはWebページの構造を記述するものなので、レイアウトや色といった見た目に関するものはこのCSSで記述します。

== CSSの構文

CSSの例を@<list>{example}に示します。

//list[example][CSSの例]{
h1 {
  color: red;
  font-size: 12px;
}
//}

h1の部分をセレクタと呼びます。どのHTML要素に対してスタイルを指定するかを記述します。color:redやfont-size:12pxを宣言と呼びます。各宣言の末尾にはセミコロンを付けます。各宣言はプロパティ:値のペアで構成されています。

=== 練習問題

次のCSSの宣言数とプロパティ名をすべて答えよ。

//emlist{
1 

h1 {
}

2

h1 {
}
 
//}

== HTML文書にCSSを適用する

HTML文書にCSSを適用するには、次の3つの方法があります。

 * style要素で記述する
 * link要素でcssファイルを読み込む
 * style属性の値で記述する

複数の文書で共通のCSSを使用することが多いため、通常はlink要素でcssファイルを読み込む方法を使います。

=== style要素で記述する

head要素の子にstyle要素を置き、その中にCSSを記述することでスタイルを適用することができます。@<list>{style-elem}はh1要素の色を赤に、h2要素の色を青に指定した例です。

//list[style-elem][style要素で記述する]{
<!DOCTYPE html>
<html>
  <head>
    <style>
    h1 {
      color: red;
    }
    h2 {
      color: blue;
    }
    </style>
  </head>
  <body>
    <h1>見出し1</h1>
    <h2>見出し2</h2>
  </body>
</html>
//}

=== link要素でcssファイルを読み込む

link要素を用いるとCSSファイルを読み込むことができます。

まず、style.cssファイルを作成します。ファイルの内容は@<list>{css-file}のようにCSSを記述します。

//list[css-file][CSSファイル]{
h1 {
  color: red;
}
h2 {
  color: blue;
}
//}

次に、@<list>{link-css}のようにlink要素で読み込むCSSファイルを指定します。ファイル名はhref属性で指定します。

//list[link-css][link要素で読み込む]{
<!DOCTYPE html>
<html>
  <head>
    <link rel="stylesheet" type="text/css" href="style.css">
  </head>
  <body>
    <h1>見出し1</h1>
    <h2>見出し2</h2>
  </body>
</html>
//}

=== style属性の値で記述する

要素に対しstyle属性でスタイルを指定することもできます。属性値には宣言のみを記述します。

//list[style-attr][style属性で指定する]{
<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
    <h1 style="color:red; font-size: 36px;">見出し1</h1>
    <h2>見出し2</h2>
  </body>
</html>
//}

== セレクタの種類

セレクタにはいくつか種類があります。ここでは代表的なセレクタを紹介します。

=== 要素セレクタ

要素セレクタはHTMLの要素名でスタイルを適用する要素を決めるセレクタです。@<list>{elem-selector}はHTML中のすべてのp要素に対し、色を赤に指定した例です。

//list[elem-selector][要素セレクタ]{
p {
    color: red;
}
//}

=== idセレクタ

HTMLの要素にはid属性で一意のIDを付与することができます。idセレクタはこのIDと一致する要素に対しスタイルを適用するためのセレクタで、#ID名で指定します。@<list>{id-selector}はIDがmainである要素に対し、背景色を青に指定した例です。

//list[id-selector][idセレクタ]{
#main {
    background:blue;
}
//}

=== クラスセレクタ

HTMLの要素にはclass属性で任意のクラス名を付与することができます。クラスセレクタは指定したクラス名が付与された要素に対しスタイルを適用するためのセレクタで、.クラス名で指定します。@<list>{class-selector}はcardというクラスが付与された要素に対し、影を付けるよう指定した例です。
 
//list[class-selector][クラスセレクタ]{
.card {
    box-shadow: 10px 10px;
}
//}

