import java.util.*;

class MovieRentingSystem {
    // movie-price mapping
    private Map<List<Integer>, Integer> priceMap;
    // available movies per movieId
    private Map<Integer, TreeSet<int[]>> available;
    // rented movies
    private TreeSet<int[]> rented;

    public MovieRentingSystem(int n, int[][] entries) {
        priceMap = new HashMap<>();
        available = new HashMap<>();

        // Comparator for available movies (price, shop)
        Comparator<int[]> cmpAvail = (a, b) -> {
            if (a[1] != b[1]) return a[1] - b[1]; // by price
            return a[0] - b[0]; // by shop
        };

        // Comparator for rented movies (price, shop, movie)
        Comparator<int[]> cmpRented = (a, b) -> {
            if (a[2] != b[2]) return a[2] - b[2]; // by price
            if (a[0] != b[0]) return a[0] - b[0]; // by shop
            return a[1] - b[1]; // by movie
        };

        rented = new TreeSet<>(cmpRented);

        // Entries ko load karna
        for (int[] e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap.put(Arrays.asList(shop, movie), price);

            available.putIfAbsent(movie, new TreeSet<>(cmpAvail));
            available.get(movie).add(new int[]{shop, price});
        }
    }

    // search: 5 cheapest shops jaha movie abhi rent nahi hui
    public List<Integer> search(int movie) {
        List<Integer> ans = new ArrayList<>();
        if (!available.containsKey(movie)) return ans;
        int count = 0;
        for (int[] entry : available.get(movie)) {
            ans.add(entry[0]); // shop id
            if (++count == 5) break;
        }
        return ans;
    }

    // rent movie from shop
    public void rent(int shop, int movie) {
        int price = priceMap.get(Arrays.asList(shop, movie));
        available.get(movie).remove(new int[]{shop, price});
        rented.add(new int[]{shop, movie, price});
    }

    // drop (return) movie to shop
    public void drop(int shop, int movie) {
        int price = priceMap.get(Arrays.asList(shop, movie));
        rented.remove(new int[]{shop, movie, price});
        available.get(movie).add(new int[]{shop, price});
    }

    // report: cheapest 5 rented movies
    public List<List<Integer>> report() {
        List<List<Integer>> ans = new ArrayList<>();
        int count = 0;
        for (int[] r : rented) {
            ans.add(Arrays.asList(r[0], r[1])); // shop, movie
            if (++count == 5) break;
        }
        return ans;
    }
}
