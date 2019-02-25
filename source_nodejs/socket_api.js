const https  =   require('https');

var prodCode = "";
var prodName = "";
function getProduct() {
    return new Promise((resolve, reject) => {
        https.get("https://world.openfoodfacts.org/api/v0/product/" + prodCode + ".json", (res) => {
            if (res.statusCode == 200) {
                let stream = "";
                res.on('data', (chunk) => {
                    stream += chunk;
                });
                res.on('end', () => {
                    prodName = JSON.parse(stream);
                    console.log(prodName.product.generic_name);
                    resolve(prodName.product.generic_name);
                });
            }
            else {
                console.log(res.statusCode);
                reject(res.statusCode);
            }
        }).on('error', (e) => {
            console.error(e);
            reject(e);
        });
    });
}

function setProduct(prod) {
    if (prod.code) {
        prodCode = prod.code;
    }
    else throw "Wrong property";
}

module.exports = {
    setProduct,
    getProduct
}