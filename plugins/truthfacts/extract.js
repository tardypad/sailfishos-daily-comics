function(page) {
    var regex = /<img[^>]*src="([^"]*\/img\/truth_facts\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
