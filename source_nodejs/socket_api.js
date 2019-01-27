// prepare the socket TCP server
var net     =   require('net');

function start(callback) {
    let socket
    let server = net.createServer(skt => {
        console.log(skt);
        socket = skt;
    }).on('error', err => {
        console.log(err);
    }).listen(1337, () => {
        console.log("TCP Server listening on: ", server.address());
    });
    console.log(socket);
    callback(new net.Socket());
}

module.exports = {
    start
};

// modules for getting messages
// modules for receiving messages

// exporting modules