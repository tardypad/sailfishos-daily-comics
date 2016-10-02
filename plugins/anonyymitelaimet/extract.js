function(page) {
    var regex = /<img[^>]*src="([^"]*\/webkuva\/sarjis[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
