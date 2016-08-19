#ifndef FLASHgg_Proton_h
#define FLASHgg_Proton_h

#include "DataFormats/VertexReco/interface/Vertex.h"

#include "flashgg/DataFormats/interface/ProtonTrack.h"
#include "flashgg/DataFormats/interface/WeightedObject.h"

namespace flashgg {

    class Proton : public WeightedObject
    {

    public:
        Proton();
        Proton( const ProtonTrack&, const ProtonTrack::Side& );
        Proton( const ProtonTrack&, const ProtonTrack&, const ProtonTrack::Side& );
        ~Proton();

        Proton *clone() const { return ( new Proton( *this ) ); }

        inline void setValid( bool valid=true ) { valid_ = valid; }
        inline bool isValid() const { return valid_; }

        inline void setSide( const ProtonTrack::Side& side ) { side_ = side; }
        inline ProtonTrack::Side side() const { return side_; }

        inline const ProtonTrack* nearTrack() const {
            for ( std::map< TotemRPDetId, ProtonTrack >::const_iterator it = tracks_map_.begin(); it != tracks_map_.end(); it++ ) {
                if ( it->first.detector()==1 ) return &(it->second); // CHECK MEEEE!
            }
            return 0;
        }
        inline const ProtonTrack* farTrack() const {
            for ( std::map< TotemRPDetId, ProtonTrack >::const_iterator it = tracks_map_.begin(); it != tracks_map_.end(); it++ ) {
                if ( it->first.detector()==0 ) return &(it->second); // CHECK MEEEE!
            }
            return 0;
        }

        /////////////////////////////////////////////////////////////
        //
        inline void setXi( float xi, float xi_err ) {
            xi_ = xi;
            xi_err_ = xi_err;
        }
        inline float xi() const { return xi_; }
        inline float xiError() const { return xi_err_; }

        /////////////////////////////////////////////////////////////

        inline void setThetaX( float thx, float thx_err ) {
            theta_x_ = thx;
            theta_x_err_ = thx_err;
        }
        inline float thetaX() const { return theta_x_; }
        inline float thetaXError() const { return theta_x_err_; }

        /////////////////////////////////////////////////////////////

        inline void setT( float t, float t_err ) {
            t_ = t;
            t_err_ = t_err;
        }
        inline float t() const { return t_; }
        inline float tError() const { return t_err_; }

        /////////////////////////////////////////////////////////////

        inline void setVertex( const edm::Ptr<reco::Vertex>& vtx ) { vtx_ = vtx; }
        inline const reco::Vertex* vtx() const { return vtx_.get(); }

    private:
        void computeXi();

        bool valid_;

        std::map< TotemRPDetId, ProtonTrack > tracks_map_;

        ProtonTrack::Side side_;

        edm::Ptr<reco::Vertex> vtx_;

        float xi_, xi_err_;
        float t_, t_err_;
        float theta_x_, theta_x_err_;
    };
}

#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

