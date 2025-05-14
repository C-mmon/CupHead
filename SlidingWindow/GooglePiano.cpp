public static int minHandRaises(int[] keys) {
        if (keys == null || keys.length == 0) return 0;

        int raises = 0;
        int curMin = keys[0], curMax = keys[0];
        for (int i = 1; i < keys.length; i++) {
            int key = keys[i];
            int candidateMin = Math.min(curMin, key);
            int candidateMax = Math.max(curMax, key);

            if (candidateMax - candidateMin <= 4) {
                curMin = candidateMin;
                curMax = candidateMax;
            } else {
                raises++;
                curMin = curMax = key;
            }
        }
        return raises;
}
return the list of thumb positions you actually use—so you can see exactly where your thumb goes for each segment


public static List<Integer> getThumbPositions(int[] keys) {
        List<Integer> res = new ArrayList<>();
        if (keys == null || keys.length == 0) return res;

        int curMin = keys[0], curMax = keys[0];
        for (int i = 1; i < keys.length; i++) {
            int key = keys[i];
            int candidateMin = Math.min(curMin, key);
            int candidateMax = Math.max(curMax, key);

            if (candidateMax - candidateMin <= 4) {
                curMin = candidateMin;
                curMax = candidateMax;
            } else {
                res.add(curMin);
                curMin = curMax = key;
            }
        }

        res.add(curMin);
        re
