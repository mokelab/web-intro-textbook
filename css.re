= CSS

//lead{
本章ではCSSの基礎について説明します。指定方法をまなび、見栄えのよいWebアプリを作れるようになりましょう。
//}

== CSSとは

CSSとはカスケーディングスタイルシートの略で、Webページの表示方法を指示するための言語です。HTMLはWebページの構造を記述するものなので、要素の配置方法や色といった見た目に関するものはこのCSSで記述します。

== CSSの構文

CSSの例を@<list>{example}に示します。

//list[example][CSSの例]{
h1 {
  color: red;
  font-size: 12px;
}
//}

h1の部分をセレクタと呼びます。セレクタではどのHTML要素に対してスタイルを指定するかを記述します。@<code>{color:red}や@<code>{font-size:12px}を宣言と呼びます。各宣言の末尾にはセミコロンを付けます。各宣言は「プロパティ名:値」のペアで構成されています。

=== 練習問題

次のCSSの宣言数とプロパティ名をすべて答えよ。

//emlist{
h1 {
  font-size: 22px;
  width: 450px;
}
p {
  border-radius: 16px;
  background-color: red;
  padding: 10px;
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

=== link要素でCSSファイルを読み込む

link要素を用いるとCSSファイルを読み込むことができます。記述するCSSの量が多い場合や、複数画面で共通の設定を使用したい場合、CSSファイル（拡張子.css）を用意し、それを読み込むといった使い方ができます。

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

== 代表的なプロパティ

本節ではCSSによるデザインでよく使われるプロパティについて説明します。すべての標準CSSプロパティは@<href>{https://developer.mozilla.org/ja/docs/Web/CSS/Reference}を参照してください。

=== 要素のサイズと色に関するプロパティ

ここでは要素のサイズと背景色の設定方法について説明します。

==== widthとheight

@<code>{width}プロパティは要素の幅を、@<code>{height}プロパティは要素の高さを設定します。値には単位付きの数値を指定します。

//list[size][widthとheight]{
<!DOCTYPE html>
<html>
  <head>
    <style>
    p {
      width: 300px;
      height: 100px;
      border: 1px solid gray;
    }  
    </style>
  </head>
  <body>
    <h1>見出し</h1>
    <p>第一段落</p>
    <p>第二段落</p>
  </body>
</html>
//}

//image[size][ブラウザで表示させた例]{
//}

==== background-color

@<code>{background-color}プロパティは要素の背景色を設定します。値には@<code>{#RRGGBB}形式のカラーコードの他、@<code>{red}や@<code>{blue}といった色名が指定できます。@<list>{background-color}は最初のp要素の背景色を黄色にした例です。

//list[background-color][背景色の指定]{
<!DOCTYPE html>
<html>
  <head>
    <style>
    p {
      border: 1px solid gray;
    }  
    </style>
  </head>
  <body>
    <h1>見出し</h1>
    <p style="background-color:yellow;">第一段落</p>
    <p>第二段落</p>
  </body>
</html>
//}

@<list>{background-color}をブラウザで表示させた例が@<img>{background-color}です。背景色が黄色になっています。

//image[background-color][背景色が黄色になった]{
//}

=== 文字に関するプロパティ

ここでは文字に関するプロパティについて説明します。

==== font-size

@<code>{font-size}プロパティは文字の大きさを設定します。値には単位付きの数値の他に、@<code>{small}や@<code>{large}といったキーワードも指定できます。@<list>{font-size}は@<code>{h1}の文字サイズを@<code>{48px}に設定した例です。

//list[font-size][font-sizeで文字の大きさを設定する]{
<!DOCTYPE html>
<html>
  <head>
    <style>
      h1 { font-size: 48px; }
    </style>
  </head>
  <body>
    <h1>見出し</h1>
    <p>段落1</p>
  </body>
</html>
//}

//image[font-size][見出しのフォントが大きくなった]{
//}



==== text-align

@<code>{text-align}プロパティはインライン要素の水平方向の配置方法を指定します。@<list>{text-align}はボタンを右端に寄せて表示させる例です。

//list[text-align][右端に寄せて表示]{
<!DOCTYPE html>
<html>
  <head>
    <style>
      .my-block { text-align: right; }
    </style>
  </head>
  <body>
    <div class="my-block">
      <button>スタート</button>
    </div>
  </body>
</html>
//}

//image[text-align][ボタンが右端に表示された]{
//}

==== color

@<code>{color}プロパティはテキストの色を設定します。色の指定方法は@<code>{background-color}と同様です。@<list>{color}はh1要素の文字色を赤に設定した例です。

//list[color][文字色を指定した例]{
<!DOCTYPE html>
<html>
  <head>
    <style>
      h1 { color: red; }
    </style>
  </head>
  <body>
    <h1>見出し</h1>
  </body>
</html>
//}

//image[color][見出しの文字色が赤になった]{
//}

=== 境界線に関するプロパティ

CSSを用いると要素に境界線を表示させることができます。

==== border-width

@<code>{border-width}プロパティは境界線の太さを設定します。値はスペース区切りで複数指定可能で、2つ指定した場合は「上下の太さ」「左右の太さ」の指定になります。

==== border-color

@<code>{border-color}プロパティは境界線の色を設定します。値の指定方法は@<hd>{color}と同様です。

==== border-style

@<code>{border-style}プロパティは境界線のスタイルを設定します。@<table>{border-style}に指定可能な値の一部を示します。

//table[border-style][border-styleに指定可能な値]{
値	説明
---------------
solid	1本の直線
double	2本の直線
dotted	連続した丸い点
dashed	連続した線分
ridge	出っ張ったような境界
//}

@<list>{border1}にこれら3つのプロパティを指定した例を示します。どれか1つでも欠けていた場合、境界線は表示されないので注意しましょう。

//list[border1][境界線を表示する例]{
<!DOCTYPE html>
<html>
  <head>
    <style>
      h1 { 
        border-width: 8px; 
        border-color: pink;
        border-style: double;
      }
    </style>
  </head>
  <body>
    <h1>見出し</h1>
  </body>
</html>
//}

//image[border][境界線が表示された]{
//}

この3つのプロパティは同時に設定されることがほとんどなため、@<code>{border}というプロパティでまとめて設定することもできます。@<list>{border2}は@<list>{border1}を@<code>{border}プロパティで書き直してみた例です。

//list[border2][borderプロパティ]{
<!DOCTYPE html>
<html>
  <head>
    <style>
      h1 {
        border: 8px pink double;
      }
    </style>
  </head>
  <body>
    <h1>見出し</h1>
  </body>
</html>
//}

=== 余白に関するプロパティ

美しいUIを開発するには余白を適切にいれることが重要です。ここでは余白をいれるためのプロパティを紹介します。

==== margin

margin（マージンと読みます）は要素と要素の間の余白を表します。@<list>{margin1}はp要素に上下8px、左右32pxのマージンを設定した例です。ブロックの境界を判別しやすくするため、境界線も設定しています。

//list[margin1][マージンを設定した例]{
<!DOCTYPE html>
<html>
  <head>
    <style>
    p {
      margin: 8px 32px;
      border: 1px solid gray;
    }  
    </style>
  </head>
  <body>
    <h1>見出し</h1>
    <p>第一段落</p>
    <p>第二段落</p>
  </body>
</html>
//}

//image[margin1][要素間に余白ができている]{
//}

==== padding

padding（パディングと読みます）は要素内の余白を表します。@<list>{padding1}は最初のp要素に対し、上下16px、左右32pxのパディングを指定した例です。パディング指定の無い2番目のp要素と表示を見比べてみましょう（@<img>{padding1}）。

//list[padding1][パディングを指定する例]{
<!DOCTYPE html>
<html>
  <head>
    <style>
    p {
      border: 1px solid gray;
    }  
    </style>
  </head>
  <body>
    <h1>見出し</h1>
    <p style="padding: 16px 32px;">第一段落</p>
    <p>第二段落</p>
  </body>
</html>
//}

//image[padding1][最初のp要素には内部に余白がある]{
//}

なお、Dev toolで要素を選択すると、@<img>{space}のようにmarginやpaddingがどのような値になっているかを確認することができます。

//image[space][marginやpaddingの値を確認する]{
//}