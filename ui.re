= UIライブラリ

//lead{
本章ではWebアプリケーション開発を助けるUIライブラリについて説明します。
//}

== DOM操作

JavaScriptは主にブラウザ上で動作し、HTMLから@<code>{script}要素で読み込まれ、実行されます。そのため、JavaScriptから読み込んだHTMLの要素を操作することができます。この操作をDOM操作と呼びます。DOMとはDocument Object Modelのことで、HTMLの要素をJavaScriptのオブジェクトとして表現したものです。

@<list>{dom1}はidが@<code>{title}であるHTML要素を取り出し、その中身をコンソールに表示する例です。

//list[dom1][DOM操作の例]{
<!DOCTYPE html>
<html>
  <head>
    <title>DOM操作</title>
  </head>
  <body>
    <h1 id="title">ここはタイトル</h1>

    <script>
      var h = document.getElementById('title');
      console.log(h.innerHTML);
    </script>
  </body>
</html>
//}

== UIライブラリとは

前節のDOM操作を用いるとHTML要素の値を取得したり書き換えたりすることができるため、うまく使うとアプリケーションが作成できます。しかしDOM操作で複雑なHTMLを組み立てるのはとても手間がかかります。この問題を解決するため、さまざまな種類のライブラリが開発されています。画面表示に関する機能を提供するライブラリなので、UIライブラリと呼ぶこともあります。

2018年時点でメジャーなUIライブラリは次の3つです。

 * Angular
 * React
 * Vue.js

AngularはGoogleが開発したライブラリで、UI以外にも多くの機能を提供しています。ReactはFacebookが開発したライブラリで、こちらはUIの部分を主に担当します。Vue.jsはオープンソースで開発されているライブラリで、徐々に人気が高まっています。

どのライブラリも学習するにはそれなりの時間がかかります。そのため本書ではRactive.jsというシンプルなUIライブラリを使用することにします。

== Ractive.js

Ractive.jsはVue.jsに近いUIライブラリです。非エンジニアでもWebアプリケーションが開発できるのを目的としているため、学習すべきことはとても少ないです。

Ractive.jsを導入するには、HTMLに次の要素を追加します。@<code>{app.js}内でRactive.jsの機能を使うため、順序に注意しましょう。

//emlist{
<!-- Ractive.jsの読み込み -->
<script src="https://cdn.jsdelivr.net/npm/ractive"></script>
<script src="app.js"></script>
//}

次に、body内に@<list>{ractive1-1}のように@<code>{div}要素と@<code>{script}要素を追加します。@<code>{id=container}な@<code>{div}はテンプレートの貼り付け先となり、@<code>{script}の中身が貼り付けるテンプレートになります。

//list[ractive1-1][containerとテンプレート]{
<div id="container"></div>
<script id="template" type="text/ractive">
  <h1>Hello Ractive world</h1>
</script>
//}

最後に、@<code>{app.js}を@<list>{ractive1-2}のようにします。@<code>{new}を使ってRactiveオブジェクトを生成し、変数@<code>{r}に代入しているだけです。@<code>{new}の詳しい説明は本書では割愛します。

//list[ractive1-2][app.js]{
var r = new Ractive({
  el: '#container',
  template: '#template'
});
//}

これを実行すると、図xxのように@<code>{script}内のHTMLが表示されます。

== テンプレート内で変数を使う

Ractive.jsではテンプレート内で変数を使うことができます。まず、@<list>{var1}のように@<code>{app.js}を修正し、@<code>{data}パラメータを追加します。

//list[var1][dataパラメータの追加]{
var r = new Ractive({
  el: '#container',
  template: '#template',
  data: {
    name: 'JavaScript'
  }
});
//}

次に、テンプレート部分を@<list>{var2}のように修正します。変数の値を表示したい部分を@<code>{{{変数名\}\}}にします。

//list[var2][テンプレートに変数をいれる]{
<script id="template" type="text/ractive">
  <h1>Hello {{name}} world</h1>
</script>
//}

変更が完了したらブラウザで実行させてみましょう。図xxのように@<code>{{{name\}\}}の部分が@<code>{data}で指定した値に置き換えられて表示されています。ここでの変数@<code>{name}はRactiveオブジェクトが保持している変数であり、@<code>{var}で作成した変数とは異なる点に注意しましょう。

== 繰り返し

変数の値に配列をセットした場合、テンプレート内で繰り返し処理ができます。例えば複数のメッセージが格納された配列を変数にセットしておき、順にリスト表示するといった使い方ができます。

例として名前をすべて表示させてみましょう。まず@<list>{for1}のように@<code>{data}に名前の入った配列をセットします。

//list[for1][配列をセットする]{
var r = new Ractive({
  el: '#container',
  template: '#template',
  data: {
    names: ['たろう', 'じろう', 'さぶろう']
  }
});
//}

次にテンプレートで繰り返し処理をしたい箇所で@<code>{{{#配列の入った変数名\}\}}を追加します。繰り返し処理の終了位置には@<code>{{{/\}\}}を追加します。各ループで配列から取り出したデータは@<code>{{{.\}\}}でアクセスできます。

//list[for2][テンプレートで繰り返し処理]{
<script id="template" type="text/ractive">
  <h1>名前一覧</h1>
  {{#names}}
  <p>{{.}}</p>
  {{/}}
</script>
//}

これをブラウザで実行すると、図xxのように表示されます。

@<list>{for1}では文字列の配列をセットしていましたが、@<list>{for3}のようにオブジェクトの配列をセットするケースもあるでしょう。

//list[for3][オブジェクトの配列]{
var r = new Ractive({
  el: '#container',
  template: '#template',
  data: {
    users: [
        {name:'たろう', age:24},
        {name:'じろう', age:18},
        {name:'さぶろう', age:9}
    ]
  }
});
//}

この場合、テンプレートでは@<list>{for4}のようにオブジェクトのキーを@<code>{{{\}\}}で指定することで、図xxのように値を取り出すことができます。

== 条件分岐

テンプレート内ではif文による条件分岐も記述することができます。変数@<code>{age}に年齢をいれておき、年齢によって表示内容を変更してみましょう。@<list>{if1}にテンプレートの例を示します。条件分岐はテンプレート内で@<code>{{{#if 条件式\}\}}で記述します。条件分岐の終了位置には@<code>{{{/if\}\}}を記述します。

//list[if1][if文による分岐]{
<script id="template" type="text/ractive">
  <h1>商品一覧</h1>
  <ul>
    <li>ラーメン</li>
    <li>ギョウザ</li>
    {{#if age >= 20}}
    <li>ビール</li>
    {{/if}}
  </ul>
</script>
//}

もし変数ageが18の場合、図xxのようにビールは表示されません。

変数ageが21の場合、図xxのようにビールは表示されます。

20歳未満の場合はビールの代わりにオレンジジュースを表示したい場合、@<list>{if2}のように@<code>{{{else\}\}}でelse節を記述することができます。@<code>{{{#else\}\}}ではない点に注意しましょう。

//list[if2][else節を記述する場合]{
<script id="template" type="text/ractive">
  <h1>商品一覧</h1>
  <ul>
    <li>ラーメン</li>
    <li>ギョウザ</li>
    {{#if age >= 20}}
    <li>ビール</li>
    {{else}}
    <li>オレンジジュース</li>
    {{/if}}
  </ul>
</script>
//}

== 双方向バインディング

テンプレート内の@<code>{input}要素の@<code>{value}属性などに変数を使用すると、双方向バインディングという仕組みが利用できます。これは、ユーザーの操作によってフォームの値が変化すると、それに応じてRactiveオブジェクトが保持している変数の値も自動的に変化する仕組みです。

@<list>{bind1}に例を示します。@<code>{h1}要素の値として使用している変数と@<code>{input}で使用している変数が同じ変数名である点に注意しましょう。

//list[bind1][双方向バインディング]{
<script id="template" type="text/ractive">
  <h1>こんにちは、{{name}}さん！</h1>
  <input type="text" value="{{name}}">
</script>
//}

これを実行し、入力フォームに文字列を入力すると、図xxのように自動的に変数nameの値が変化することがわかります。

== イベント処理と変数

最後にイベント処理の方法を説明します。「フォーカスがあたった」や、「ボタンがクリックされた」という事象はイベントと呼ばれます。Ractive.jsではイベントが発生したときの処理を記述することができます。

まず、@<list>{event1}のように@<code>{app.js}を修正します。@<code>{r.on()}は「このイベントが発生したとき、この処理をやりましょう」という対応を設定するためのメソッドです。ここではclickedというイベントが発生したとき、値としてセットした関数を実行してねという指示になります。

//list[event1][イベント発生時の処理を記述する]{
var r = new Ractive({
  el: '#container',
  template: '#template',
});
r.on({
  clicked: function() {
    var name = r.get('name');
    alert('こんにちは！' + name + 'さん！');
  }
});
//}

次に、テンプレートでは@<code>{on-click="イベント名"}で実行したいイベントを設定します。@<list>{event2}ではボタンのクリック時に@<code>{clicked}イベントが実行されるよう設定しています。

//list[event2][イベントの設定]{
<script id="template" type="text/ractive">
  <input type="text" value="{{name}}">
  <button on-click="clicked">開始</button>
</script>
//}

これをブラウザで実行し、入力欄に名前を入力した後ボタンをクリックすると、図xxのようにアラートが表示されます。イベント処理中の@<code>{r.get('name')}は、Ractiveオブジェクトに保持している変数の値を教えてもらう処理です。

== カウントアップアプリケーション

本書の最後に、ボタンをクリックするとカウンタの値が1ずつ増えていくアプリケーションを開発してみましょう。

まず、カウンタの値を@<code>{count}という変数に入れておくことにしましょう（@<list>{app1}）。

//list[app1][変数を用意する]{
var r = new Ractive({
  el: '#container',
  template: '#template',
  data: {
    count: 0
  }
});
//}

次に、ボタンをクリックした時にカウントを1つ増やす処理を記述します（@<list>{app2})。Ractive内の変数を更新するには、@<code>{r.set()}メソッドを使用します。

//list[app2][カウントアップ処理]{
r.on({
  clicked: function() {
    var count = r.get('count');
    count++;
    r.set('count', count)
  }
});
//}

最後に、テンプレートでカウンタの値を表示し、カウントアップのためのボタンを配置しましょう（@<list>{app3}）。

//list[app3][テンプレート]{
<script id="template" type="text/ractive">
  <p>カウンタの値は{{count}}</p>
  <button on-click="clicked">カウントアップ</button>
</script>
//}

これを実行し、ボタンをクリックすると図xxのようにカウントが1つずつ増えていきます。

== まとめ

本章ではUIライブラリとしてRactive.jsの簡単な使い方を説明しました。うまく使うことでWebアプリケーションを開発できるようになりましょう。