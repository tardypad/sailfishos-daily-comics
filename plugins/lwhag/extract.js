function(page) {
    var regex = /<img[^>]*src="([^"]*english[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
