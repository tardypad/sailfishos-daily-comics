function(page) {
    var regex = /<!-- Main Image -->\n.*\n.*<img[^>]*src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
