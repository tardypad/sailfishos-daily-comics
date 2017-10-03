function(page) {
    var regex = /<img[^>]*src="(\/\/hs.mediadelivery.fi\/img\/[^"]*)"/;
    var match1 = regex.exec(page);
    return match1[1];
}
