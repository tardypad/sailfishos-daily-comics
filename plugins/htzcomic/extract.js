function(page) {
    var regex = /<img[^>]*src="(http:\/\/www.htzcomic.com\/comics\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
