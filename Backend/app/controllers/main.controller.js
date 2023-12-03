exports.get=(req, res) => {

  console.log(req.file);

  
  var isPostman=req.body.postman;

  var img;
  if(isPostman=='post'){
    img= req.body.img;}
    else{
      img = req.file.filename;
    }

  var ele=[];
  
  const { spawn } = require('child_process');
  const pyProg = spawn('python', ['Python/detection.py',img,isPostman]);
  console.log('test');
  pyProg.stdout.on('data', function(data) {
    const promise1 = new Promise((resolve,reject) => {
      if(data.toString().replace(/\r/g,'').replace(/\n/,'')!='()' || '')
      {
        objects=[];
         objects=data.toString().replace(/\r/g,'').split('\n')
         var filtered = objects.filter(function(value, index, arr){ 
            return value != '';
            
        });
        var obj=['nothing'];
        for(i in filtered) {
          filtered[i]=array[filtered[i]-1].toString().replace('\r','');

          if(filtered[i]=='dog' || filtered[i]=='cat' || filtered[i]=='bird'){
            obj=filtered[i];
            break;
          }
        }
        ele=[obj];
      }
      else{
        ar =['nothing'];
        ele=ar
      }
     // ele=data.toString();;jhk
      resolve('asd');
    });

    promise1.then(() => {
      var objToJson = { };
      objToJson.message = ele;
      console.log(objToJson)
      res.write(JSON.stringify(objToJson), function(err) { res.end(); });
          
    });        
  });
  pyProg.stderr.on('data', (data) => {
    console.log(data.toString());
    res.status(400).send({ message: 'objects.toString(' })
});

}
