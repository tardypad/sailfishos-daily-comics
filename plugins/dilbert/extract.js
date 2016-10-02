function(page) {
    var regex = /<img[^>]*img-comic.*src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
