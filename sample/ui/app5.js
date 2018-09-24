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
