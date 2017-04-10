function(page) {
    var regex = /<img[^>]*src="([^"]*db-comics[^"]*)"/;
    var match = regex.exec(page);
    return match[1].replace(/&#x2F;/g, '/');
}
