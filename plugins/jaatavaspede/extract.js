function(page) {
    var regex = /<img[^>]*data-original="(\/\/hs.mediadelivery.io\/img\/[^"]*)"/;
    var match1 = regex.exec(page);
    return match1[1];
}
