function(page) {
    var regex = /<img[^>]*data-original="(\/\/hs.mediadelivery.io\/img\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
