function(page) {
    var regex = /<img[^>]*src="([^"]*\/.a\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
