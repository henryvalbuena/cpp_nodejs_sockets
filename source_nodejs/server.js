const TCP_HOST      =   process.env.HOST || 'localhost';
const TCP_PORT      =   process.env.PORT || 1337;
const net           =   require('net');

const server = net.createServer((socket) => {
  console.log("CONNECTION RECEIVED");
  socket.on('data', data => {
    parseBody(data).then(body => {
      console.log(body);
    }, err => {
      console.log(err);
    }).then(() => {
        console.log("SENDING RESPONSE...");
      socket.write("This is the Server response.");
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