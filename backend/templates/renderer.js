var fs=require('fs');
var Mustache=require('mustache');
 console.log(Mustache.render("{{title}} spends {{calc}}", {title:'foker',calc:5}));