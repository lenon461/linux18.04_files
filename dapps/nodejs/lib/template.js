
module.exports = {
  HTML:function(title, body, control){
    return `
    <!doctype html>
    <html>
    <head>
      <title>WEB1 - ${title}</title>
      <meta charset="utf-8">
    </head>
    <body>
      <h1><a href="/">WEB</a></h1>
      <h2>\
      ${control}
      ${body}
    </body>
    </html>
    `;
  },list:function(filelist){ //<div><input type="checkbox" id="checkdidol1"/> <span id = "idol1"/></div>
    var list = '<ul>';
    var i = 0;
    while(i < filelist.length){
      list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
      i = i + 1;
    }
    list = list+'</ul>';
    return list;
  }
}
