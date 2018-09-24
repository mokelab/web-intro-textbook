var r = new Ractive({
  el: '#container',
  template: '#template',
  data: {
    count: 0
  }
});
r.on({
  clicked: function() {
    var count = r.get('count');
    count++;
    r.set('count', count)
  }
});
