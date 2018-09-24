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
