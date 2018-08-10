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



== セレクタの種類

セレクタにはいくつか種類があります。

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

