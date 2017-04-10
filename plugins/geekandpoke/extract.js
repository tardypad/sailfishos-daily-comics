function(page) {
    var regex = /&lt;img[^&]*src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
