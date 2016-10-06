function(page) {
    var regex = /<img[^>]*src="([^"]*.media.tumblr.com\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
