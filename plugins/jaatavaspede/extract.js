function(page) {
    var regex = /<img[^>]*srcset="(\/\/hs.mediadelivery.fi\/img\/[^ ]*) /;
    var match1 = regex.exec(page);
    return match1[1];
}
