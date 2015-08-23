public NodeC convertTtoBT (char[] values) {
    NodeC n = new NodeC (values[0]);

    for (int i = 1; i < values.length; i += 2) {
        if (values[i] == '?') {
            n.left = new NodeC (values[i + 1]);
            n = n.left;
        }
        else if (values[i] == ':') {
            n = n.parent;
            while (n.right != null && n.parent != null ) {
                n = n.parent;
            }                    
            n.right = new NodeC (values[i + 1]);
            n = n.right;
        }
    }
    return n;