var fs=require('fs');
var _=require('lodash');
var Mustache=require('mustache');
data=JSON.parse(fs.readFileSync('./data.json'),'utf8');
function compile(file){
  fs.writeFileSync('./compiled/'+file,Mustache.render(fs.readFileSync('./'+file,'utf8'), data));
}

var files=fs.readdirSync('./admin');
_.each(files,function(file){compile('admin/'+file)});
