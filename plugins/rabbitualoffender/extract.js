function(page) {
    var regex = /<img[^>]*src="([^"]*media.tumblr.com\/[^"]*)"/;
    var match1 = regex.exec(page);
    var match2 = regex.exec(page);
    return match2[1];
}
