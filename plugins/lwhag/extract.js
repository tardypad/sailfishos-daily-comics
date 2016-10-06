function(page) {
    var regex = /<img[^>]*src="([^"]*)"[^>]*alt="[^"]*english"/;
    var match = regex.exec(page);
    return match[1];
}
