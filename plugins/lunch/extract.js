function(page) {
    var regex = /<img[^>]*src="([^"]*\/tegneserie\/[^"]*strip=lunch)"/;
    var match = regex.exec(page);
    return match[1];
}
