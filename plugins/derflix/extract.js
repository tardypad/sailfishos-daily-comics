function(page) {
    var regex = /<img[^>]*src="(http:\/\/der-flix.com\/media\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
