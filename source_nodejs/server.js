const TCP_HOST      =   process.env.HOST || 'localhost';
const TCP_PORT      =   process.env.PORT || 1337;
const net           =   require('net');

var pkg;
var jsn = { name: "Roy"};

const server = net.createServer((socket) => {
  console.log("CONNECTION RECEIVED");
  socket.on('data', data => {
    parseBody(data).then(body => {
      console.log(body);
      pkg = JSON.parse(body);
    }, err => {
      console.log(err);
    }).then(data => {
        console.log("SENDING RESPONSE..." + pkg);
        if (pkg.id == 12)
          socket.write(JSON.stringify(jsn));
        else
        socket.write(JSON.stringify({msg:"Wrong ID"}));
    });
  }).on('end', () => {
    console.log("CONNECTION ENDED");
  }).on('error', err => {
      console.log(err);
  });
}).on('error', (err) => {
  // handle errors here
  throw err;
});

function parseBody(chunk) {
  let body = "";
  return new Promise((done, err) => {
    body += chunk;
    if (body) done(body);
    else err("No data");
  });
}

server.listen(TCP_PORT, TCP_HOST, () => {
  console.log("Make sure to set IP and PORT for the server");
  console.log("TCP Server listening on: ", server.address());
});