function(page) {
    var regex = /&lt;img[^&]*src="([^"]*media.tumblr.com[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
