function(page) {
    var regex = /<img[^>]*src="([^"]*\/files\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
