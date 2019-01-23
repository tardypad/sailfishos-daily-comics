function(page) {
    var regex = /<img[^>]*srcset="(\/\/hs.mediadelivery.fi\/img\/[^ ]*) /;
    var match = regex.exec(page);
    return match[1];
}
