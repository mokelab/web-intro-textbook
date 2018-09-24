= 開発に使用するツール

//lead{
本章ではWebアプリ開発で使用するツールについて説明します。
//}

== Google Chrome

Google Chrome（以下Chromeと表記）はWebブラウザの1つで、Googleが開発しています。Webアプリ開発のための機能が充実しているので、本書ではこれを使用します。

//image[chrome][Google Chrome][scale=0.5]{
//}

=== インストール

Chromeをインストールするには、Microsoft EdgeやSafariで次のサイトにアクセスします。

https://www.google.com/intl/ja/chrome/

=== Dev Toolsを起動する

Chromeのインストールが完了し、起動できたら今度はDev Toolsを起動してみましょう。

Dev Toolsを起動するには、アドレスバーの右端にある3点アイコンをクリックし、「その他のツール」→「デベロッパー ツール」を選びます（@<img>{devtool1}）。

//image[devtool1][Dev toolsの起動][scale=0.8]{
//}


Dev Toolsが起動すると@<img>{devtool2}のような表示になります。状況によっては@<img>{devtool3}のようにウィンドウの下側に表示されることもあります。

//image[devtool2][Dev tools][scale=0.8]{
//}

//image[devtool3][ウィンドウの下側に表示された例][scale=0.8]{
//}

== Visual Studio Code

Visual Studio Code（以下VSCodeと表記）は、マイクロソフトが開発した無料のソースコードエディタです。さまざまなプラグインが用意されており、Webアプリ開発だけでなく、サーバーサイドやスマホアプリ開発にも使用することができます。

=== インストール

VSCodeをインストールするには、次のサイトにアクセスします。

https://code.visualstudio.com/

=== 作業用フォルダを開く

VSCodeでWebアプリ開発をはじめるには、作業用フォルダを作成し開く必要があります。まず、Cドライブの直下にdevという名前のフォルダを作成し、その中にlessonというフォルダを作成しましょう（@<img>{vscode1}）。

//image[vscode1][フォルダを作成する][scale=0.5]{
//}

MacやLinuxの場合は、ホームディレクトリの下にdevという名前のフォルダを作成し、その中にlessonというフォルダを作成します。

次に、VSCodeを起動します。すると@<img>{vscode2}のような「ようこそ」タブが表示されます。この中に「フォルダを開く」というリンクがあるのでクリックし、先ほど作成したlessonフォルダを選択します。これで作業用フォルダを開くことができました。

//image[vscode2][ようこそ画面][scale=0.8]{
//}