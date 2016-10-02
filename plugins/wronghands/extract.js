function(page) {
    var regex = /<img[^>]*src="(.*wronghands1.files.wordpress.com\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
