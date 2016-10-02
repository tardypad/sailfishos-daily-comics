function(page) {
    var regex = /<img[^>]*src="(https:\/\/thehatandfat.files.wordpress.com\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
