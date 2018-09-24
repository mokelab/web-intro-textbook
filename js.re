= JavaScript

//lead{
本章ではJavaScriptの基礎について説明します。Webアプリケーション開発では避けて通れないものなので、身につくまで繰り返し学習しましょう。
//}

== JavaScriptとは

JavaScriptとはプログラミング言語の1つです。言語名にJavaが含まれていますが、プログラミング言語Javaとは関係ない点に注意しましょう。JavaScriptはブラウザ上で実行されることが多いですが、Node.jsの登場によりサーバーサイドでも実行されるようになりました。Cloud Functions for FirebaseやAWS Lambdaといったサービスでは、関数を記述するための言語としてJavaScriptがサポートされています。このように、JavaScriptは多くの分野で利用されているプログラミング言語であることがわかります。本書ではブラウザで実行されることを前提としたJavaScriptの書き方を学びます。

== Chrome Dev tool

各ブラウザにはWebアプリ開発のためのツールが用意されています。まずはこのツールを用いてJavaScriptを実行してみましょう。

Google Chromeの場合は、開発対象のHTMLを表示した状態で右上の3点メニューから「その他のツール」→「デベロッパーツール」を選びます。すると、図xxのようにウィンドウが分割され、開発用ツールが表示されます。

開発ツールが表示されたら、「Console」タブを選択しましょう（コンソールと呼びます）。ここではJavaScriptの文を記述し、すぐ実行することができます。練習として、@<code>{console.log('Hello world');}を実行してみましょう。実行すると、図xxのように「Hello world」が表示されます。@<code>{console.log()}とはこのコンソールに文字列を表示する命令です。Javaをすでに学んでいる方であれば、@<code>{System.out.println()}みたいな命令という認識で大丈夫です。

== HTML文書内でJavaScriptを記述する

CSSでは@<code>{<style>}要素を用いてHTML文書内にCSSを記述することができました。JavaScriptも同様にHTML文書内に記述することができます。

HTML文書内でJavaScriptを記述し実行するには、@<code>{<script>}要素を使用します。

//list[html-js][script要素でJavaScriptを記述する]{
<!DOCTYPE html>
<html>
  <head>
    <title>Script要素でJavaScriptを記述する</title>
  </head>
  <body>

    <script>
      console.log('Hello world');
      console.log('Hello JavaScript');
    </script>
  </body>
</html>
//}

@<code>{<script>}要素は@<list>{html-js2}のように複数記述することができます。この場合、JavaScriptは上から順に実行されます。

//list[html-js2][script要素を複数記述した例]{
<!DOCTYPE html>
<html>
  <head>
    <title>Script要素でJavaScriptを記述する</title>
  </head>
  <body>
    <script>
        console.log('Hello world');
    </script>
    <script>
        console.log('Hello JavaScript');
    </script>
  </body>
</html>
//}

== 外部jsファイルを読み込む

@<code>{script}要素を使うと、JavaScriptファイル（拡張子.js）を読み込んで実行することができます。HTML文書内に長いJavaScriptを記述するとHTMLが読みにくくなってしまうため、Webアプリ開発ではこの方法を使用しましょう。

まず、@<code>{app.js}ファイルをHTMLと同じフォルダに作成します。

//list[js-file1][app.jsファイル]{
console.log('Hello world');
//}

次に、@<code>{script}要素を用いて@<code>{app.js}ファイルを読み込みます。読み込むファイルの指定は@<code>{src}属性で指定します。外部ファイルを読み込む場合、@<code>{script}要素の中身は空にしておきます。

//list[js-file2][script要素で読み込む]{
<!DOCTYPE html>
<html>
  <head>
    <title>Script要素でJavaScriptファイルを読み込む</title>
  </head>
  <body>

    <script src="app.js"></script>
  </body>
</html>
//}

もしファイル名が間違っていた場合は図xxのようにコンソールにエラーが表示されます。「あれ、実行されないな？」というときはコンソールを見るようにしましょう。

== 変数と定数

JavaScriptではデータの入れ物として変数が使用できます。変数を作るには@<code>{var 変数名;}と記述します。@<list>{var1}では@<code>{name}という変数と@<code>{age}という変数を作成しています。

//list[var1][変数を作る]{
var name;
var age;
//}

変数に値を入れるには@<code>{変数名 = 値;}と記述します。@<list>{var2}では@<code>{name}という変数に文字列fkmを、@<code>{age}という変数に34を入れています。変数に値を入れることを、「値を代入する」と呼びます。

//list[var2][変数に値を入れる]{
var name;
var age;

name = 'fkm';
age = 34;
//}

@<list>{var3}のように、変数の作成と代入を同時に行うこともできます。

//list[var3][変数の作成と代入]{
var name = 'fkm';
var age = 34;
//}

@<code>{var}で作成した変数には値を何度も代入できます。

//emlist[値を何度も代入する]{
var name = 'fkm';
name = 'moke';
name = 'Hirokazu Fukami';
//}

@<code>{var}の代わりに@<code>{const}を使用すると、一度だけ値を代入可能な定数を作ることができます。定数に対し後から別の値を代入しようとすると図xxのようにエラーとなります。

//emlist[定数を作る]{
const name = 'fkm';
name = 'moke'; // エラー　定数には後から代入できない
//}

JavaScriptでは変数や定数に型名を書くことができません。そのため@<list>{var-type}のように文字列が入っている変数に対し、後から数値を代入することもできます。

//list[var-type][変数には型がない]{
var a = 'fkm';
a = 34; // エラーにならない！
//}

変数にどのような型のデータが代入されているかを調べるには、@<code>{typeof(変数名)}を使用します。

//emlist{
> a = 'fkm'
  "fkm"
> typeof(a)
  "string"
> a = 34
  34
> typeof(a)
  "number"
//}

== JavaScriptのデータ型

本節ではJavaScriptのデータ型について説明します。

=== 数値（number）

2や3.14といった数値を表す型です。CやJavaといった言語では整数型と浮動小数点型で別のデータが用意されていますが、JavaScriptではすべて@<code>{number}という型で扱われます。そのため、@<list>{number1}のように整数/整数の結果が小数となる点に注意しましょう。

//list[number1][数値型]{
> 5 / 3
  1.6666666666666667
//}

小数点以下を切り捨てた計算をしたい場合は@<code>{Math.floor()}などを使用します。

//emlist{
> Math.floor(5 / 3)
  1
//}

=== 文字列（string）

@<code>{''}や@<code>{""}で囲まれたデータは文字列型になります。@<code>{''}と@<code>{""}の違いは文字列中でのシングルクォート（@<code>{'}）とダブルクォート（@<code>{"}）の扱いが異なる点のみです。ダブルクォートで囲んだ場合は@<list>{quot1}のようにシングルクォートはそのまま書けますが、シングルクォートで囲んだ場合は@<list>{quot2}のように\でエスケープする必要があります。

//list[quot1][ダブルクォート内ではシングルクォートがそのまま使える]{
var msg = "I'm here!";
//}

//list[quot2][シングルクォート内ではエスケープが必要]{
var msg = 'I\'m here!';
//}

=== 真偽値（boolean）

真（true）と偽（false）のどちらかを表す型です。条件分岐などで使用します。

//emlist{
var hasPC = true;
var isVisible = false;
//}

=== オブジェクト（object）

オブジェクト型とはいくつかのデータをひとまとめにしたデータ型です。オブジェクト内のデータはキーと対応する値のペアで保存されています。オブジェクト型のデータを作るには、@<list>{type-object}のように@<code>{{\}}を使用します。

//list[type-object][オブジェクト型]{
var a = {
  name: 'fkm',
  age: 34
};
console.log(a.name); // fkmが表示される
//}

=== 関数（function）

JavaScriptでは関数（＝プログラム）もデータとして変数にいれることができます。詳しくはxx節で説明します。

//emlist{
var f = function(x) {
  return x + 1;
};
console.log(f(3)); // 4が表示される
//}

== 条件分岐

通常、JavaScriptプログラムは上から順に実行されます。しかし特定の条件のときだけ実行したい命令や、特定の条件以外のみ実行したい命令というのもあるでしょう。このように何かの判断によって処理を分岐させることを条件分岐と呼びます。

JavaScriptで条件分岐を行うには、if文という構文を使用します。構文自体はCやJavaといった言語と同様なので、すでに知っている方もいるかもしれません。@<list>{if1}は、変数moneyの値が110未満のときにメッセージを表示するJavaScriptプログラムです。

//list[if1][if文]{
var money = 200;
if (money < 110) {
  console.log('ジュース買えない。。。');
}
//}

ifの後の()内に条件式を記述します。条件式には次のようなものがあります。

//table[cond][条件式]{
条件式	説明
--------------------
a == b	aとbが等しい時にtrue
a != b	aとbが等しくない時にtrue
a < b	aがbより小さいときにtrue
a <= b	aがbと等しいか、小さいときにtrue
a > b	aがbより大きいときにtrue
a >= b	aがbと等しいか、大きいときにtrue
//}

== 繰り返し

JavaScriptでは、繰り返し処理を行うための構文が3つ用意されています。

 * for文
 * while文
 * do-while文

CやJavaでもこの構文が用意されているので、すでに学んでいる方は復習のつもりで読み進めてください。

=== for文

for文は主に繰り返す回数が事前に判明しているときに使用する構文です。@<list>{for1}は、コンソールに1から10まで順に表示させるプログラムです。

//list[for1][for文]{
for (var i = 1 ; i <= 10 ; i++) {
  console.log(i);
}
//}

for文の()の中はセミコロンで3つの部分に区切られます。最初の@<code>{var i = 1}の部分は、繰り返し処理の開始前に一度だけ実行されます。ここでは繰り返し回数を数えておくための変数（ループ変数と呼びます）を用意し、初期値をいれておきます。次の@<code>{i <= 10}の部分は繰り返しを継続する条件を記述します。最後の@<code>{i++}の部分は、for内の処理が終わった時点で毎回呼ばれます。ほとんどの場合、繰り返し回数を1増やす処理を記述します。

@<list>{for1}ではループ変数の初期値を1にしましたが、多くの場合は@<list>{for2}のように初期値を0とし、繰り返す条件を@<code>{ループ変数 < 繰り返したい回数}とします。

//list[for2][n回繰り返す]{
for (var i = 0 ; i < n ; i++){
  console.log(i)
}
//}

=== while文

繰り返し処理の中には事前に繰り返す回数がわからないものもあります。例えばデータを順に読み込み、-1がでてきたら繰り返し処理を終了するといったケースです。この場合はwhile文を使用します。@<list>{while1}は@<code>{Math.random()}の結果が0.2以上の間繰り返す例です。@<code>{Math.random()}は0以上1未満のランダムな値を返す関数で、呼ぶ度に結果が変わります。

//list[while1][while文]{
var v = Math.random();
while (v >= 0.2) {
  console.log(v);
  v = Math.random();
}
//}

while文では、ループの最中に条件として使用している変数の値が変化することを前提としています。もし@<list>{while2}のようにループの最中に条件として使用している変数の値が変化しない場合、ループを抜け出すことができず、無限ループとなってしまいます。

//list[while2][無限ループ]{
var v = Math.random() + 0.2;
while (v >= 0.2) {
  console.log(v);
  // あれ、vの値は変化しないぞ？
}
//}

=== do-while文

do-while文はwhile文と似ていますが、ループ内の処理を必ず1回は実行するという違いがあります。@<list>{dowhile}にdo-while文の例を示します。do-while文が必要となる場面はかなり少ないので、繰り返し処理をfor文やwhile文で書けないか検討してみましょう。

//list[dowhile][do-while文]{
do {
  var v = Math.random();
  console.log(v);
} while (v >= 0.2);
//}

== 配列

配列とはデータを一列に並べて格納するデータ型です。並んでいる各データにアクセスするには、@<code>{配列名[インデックス]}でアクセスします。@<list>{array1}はデータが3つ入っている配列を使用した例です。

//list[array1][配列を使う]{
var a = ['いちろう', 'じろう', 'さぶろう'];
console.log(a[1]); // じろう　が表示される
a[2] = '三郎';
//}

CやJavaにも配列はありますが、各データの型を事前に決めておく必要があります。これに対し、JavaScriptの配列は各データの型を事前に決めておく必要はなく、またいろんな型を混ぜて格納することもできます。

//list[array2][JavaScriptの配列には自由にデータを入れることができる]{
var a = ['いちろう', 2345, true, [1, 2]];
b = a[3]; // 3番目には長さ2の配列が入っている
console.log(b[1]); // 2が表示される
//}

=== 配列の中身を順に取り出す

@<code>{配列名.length}で配列の長さが取得できます。これとfor文を組み合わせると、@<list>{array-for}のように配列の中身を先頭から順に取り出すプログラムが作成できます。

//list[array-for][for文で順に取り出す]{
var a = ['いちろう', 'じろう', 'さぶろう'];
for (var i = 0 ; i < a.length ; i++) {
  console.log(a[i]);
}
//}

=== 配列のメソッド

JavaScriptの配列はオブジェクトなので、配列に対しメソッド呼び出しができます。@<table>{array-method}に主なメソッドを示します。詳細は@<href>{https://mokelab.com}を参照してください。

//table[array-method][配列の主なメソッド]{
メソッド名	説明
--------------------
array.push(v)	末尾にvを追加する
array.pop()	末尾の要素を削除する
array.shift()	先頭の要素を削除する
array.unshift(v)	先頭にvを追加する
array.indexOf(v)	vが入っている位置を取得する
//}

@<list>{array-method-sample}は配列に対しメソッド呼び出しをすることで、配列操作を行う例です。CやJavaでは、一度作成した配列の長さは変更できませんが、JavaScriptの配列は@<code>{push()}や@<code>{pop()}などといった操作で長さが動的に変化する点に注意しましょう。

//list[array-method-sample][配列操作]{
var a = []; // 空の配列を作る
a.push('いちろう');
a.push('じろう');
console.log(a.length); // 要素が2つ入っているので、2が表示される
console.log(a.pop()); // じろう が表示される
console.log(a.length); // 長さは1になっているので、1が表示される
//}

== 関数

3つの商品の税込価格をコンソールに表示するプログラムを作成してみましょう。ぱっと思いつくのは@<list>{func1}のようなプログラムでしょう。

//list[func1][税込価格を表示するプログラム]{
console.log('100円の商品の税込価格は' + Math.floor(100 * 1.08) + '円だよ');
console.log('299円の商品の税込価格は' + Math.floor(299 * 1.08) + '円だよ');
console.log('1152円の商品の税込価格は' + Math.floor(1152 * 1.08) + '円だよ');
//}

このプログラムを作成後、消費税率が10%に変更になった場合、@<list>{func2}のように@<code>{1.08}の部分をすべて@<code>{1.1}に書き換えなければなりません。

//list[func2][税込価格を表示するプログラム]{
console.log('100円の商品の税込価格は' + Math.floor(100 * 1.1) + '円だよ');
console.log('299円の商品の税込価格は' + Math.floor(299 * 1.1) + '円だよ');
console.log('1152円の商品の税込価格は' + Math.floor(1152 * 1.1) + '円だよ');
//}

3箇所ぐらいであれば修正漏れはないかもしれません。しかしプログラムが大きく、税込計算をしている箇所が散らばっている場合は修正漏れが生じてしまうかもしれません。ここで登場するのが「関数」という仕組みです。同じ計算や処理を「関数」にまとめ、部品のように使うことができます。@<list>{func1}で部品化できそうなのは税込計算をしている部分です。これを関数を使って部品化してみた例が@<list>{func3}です。もし消費税率が変更になった場合は、@<code>{calc()}関数内の@<code>{1.08}のみを修正すればよいので、修正箇所も少なくて済みます。

//list[func3][関数calc()を定義し、使ってみた例]{
// 関数を定義する      
function calc(price) {
  return Math.floor(price * 1.08);
}
// calc()関数を使ってみる
console.log('100円の商品の税込価格は' + calc(100) + '円だよ');
console.log('299円の商品の税込価格は' + calc(299) + '円だよ');
console.log('1152円の商品の税込価格は' + calc(1152) + '円だよ');
//}

JavaScriptで関数を定義するには、@<code>{function 関数名(引数名)}とし、@<code>{{\}}の中に呼ばれた時の処理を記述します。引数とは関数を実行するのに必要なデータで、関数内の処理を実行中は変数として扱うことができます。@<code>{return}文は呼び出し元に結果を返し、処理を終了させるための命令です。

定義した関数を呼ぶには@<code>{関数名(引数)}と記述します。引数の無い関数を呼ぶには@<code>{関数名()}のように@<code>{()}を記述します。

JavaScriptの関数はデータでもあるので、@<list>{func4}のように変数に代入することもできます。関数を「呼ばれるとどのような処理をするか手順が書かれている紙」とするとイメージしやすいでしょう。

//list[func4][関数はデータでもある]{
// 関数を定義する      
var calc = function(price) {
  return Math.floor(price * 1.08);
};
// calc()関数を使ってみる
console.log('100円の商品の税込価格は' + calc(100) + '円だよ');
console.log('299円の商品の税込価格は' + calc(299) + '円だよ');
// calc2にもcalcと同じ関数を入れる
var calc2 = calc;
// calc2にも関数が入っているので、呼べる
console.log('1152円の商品の税込価格は' + calc2(1152) + '円だよ'); 
//}

関数は一連の処理に名前をつけるという役割もあります。上手に名前をつけることで、後から読みやすいプログラムを作成できるようになりましょう。

