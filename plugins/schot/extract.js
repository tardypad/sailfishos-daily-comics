function(page) {
    var regex = /<img\ssrc="([^"]*)"/;
    var match = regex.exec(page);
//    return match[1];
    return match[1].replace('\/thumbs', '');
}
