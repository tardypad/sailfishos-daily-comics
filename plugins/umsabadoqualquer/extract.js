function(page) {
    var regex = /<img[^>]*src="([^"]*\/wp-content\/uploads\/[^"]*\/[0-9]*-[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
