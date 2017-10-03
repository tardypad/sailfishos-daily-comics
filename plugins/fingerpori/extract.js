function(page) {
    var regex = /<img[^>]*src="(\/\/hs.mediadelivery.fi\/img\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
